#include "Commands.h"

#include <intrin.h>

#include <Logger/Logger.h>

#include <Tools.h>

#include "IBaseApi.h"
#include "Helpers.h"
#include "PluginManager/PluginManager.h"

namespace ArkApi
{
	namespace
	{
		HMODULE GetApiModule()
		{
			static const HMODULE module = API::GetModuleFromAddress(reinterpret_cast<const void*>(&GetApiModule));
			return module;
		}

		std::string ToString(const FString& text)
		{
			return text.IsEmpty() ? std::string() : Tools::Utf8Encode(*text);
		}
	}

	template <typename T>
	void Commands::AddCommand(const FString& command, const std::function<T>& callback, Registry<T>& registry,
	                          void* return_address, bool unique_name)
	{
		const HMODULE owner = API::GetModuleFromAddress(return_address);
		std::string owner_name = API::GetModuleName(owner);

		{
			// a new image at the address of a purged one
			std::lock_guard<std::mutex> lock(purged_mutex_);
			purged_modules_.erase(owner);
		}

		if (unique_name)
		{
			const auto list = registry.Snapshot();
			for (const auto& entry : *list)
			{
				if (entry->command == command)
				{
					Log::GetLog()->warn("Command {} from {} is already registered by {}, the first registration is used",
					                    ToString(command), owner_name, entry->owner_name);
					break;
				}
			}
		}

		registry.Add(std::make_shared<Command<T>>(command, callback, owner, std::move(owner_name)));
	}

	template <typename T>
	bool Commands::RemoveCommand(const FString& command, Registry<T>& registry, void* return_address, bool protect_api)
	{
		const HMODULE caller = API::GetModuleFromAddress(return_address);

		bool caller_owns = false;
		{
			const auto list = registry.Snapshot();
			for (const auto& entry : *list)
			{
				if (entry->owner == caller && entry->command == command)
				{
					caller_owns = true;
					break;
				}
			}
		}

		if (!caller_owns)
		{
			std::lock_guard<std::mutex> lock(purged_mutex_);
			if (purged_modules_.count(caller) != 0)
			{
				return false;
			}
		}

		// one entry per call: the caller's own, otherwise the first with that name
		bool found = false;
		const auto removed = registry.RemoveIf([&](const std::shared_ptr<Command<T>>& entry)
		{
			if (found || !(entry->command == command))
			{
				return false;
			}

			if (caller_owns ? entry->owner != caller : protect_api && entry->owner == GetApiModule())
			{
				return false;
			}

			found = true;
			return true;
		});

		return !removed.empty();
	}

	template <typename T>
	void Commands::RemoveModuleEntries(HMODULE module, Registry<T>& registry, const char* kind)
	{
		const auto removed = registry.RemoveIf([module](const std::shared_ptr<Command<T>>& entry)
		{
			return entry->owner == module;
		});

		for (const auto& entry : removed)
		{
			Log::GetLog()->warn("Plugin {} did not remove its {} {}, removing it", entry->owner_name, kind,
			                    ToString(entry->command));
		}
	}

	template <typename T, typename Fn>
	bool Commands::Invoke(Command<T>& entry, const char* kind, Fn&& call)
	{
		++entry.running;

		if (entry.removed)
		{
			--entry.running;
			return false;
		}

		try
		{
			call(entry.callback);
		}
		catch (const std::exception& error)
		{
			Log::GetLog()->error("Plugin {} threw in {} {}: {}", entry.owner_name, kind, ToString(entry.command),
			                     error.what());
		}
		catch (...)
		{
			Log::GetLog()->error("Plugin {} threw in {} {}", entry.owner_name, kind, ToString(entry.command));
		}

		--entry.running;
		return true;
	}

	template <typename T, typename... Args>
	bool Commands::CheckCommands(const FString& message, const Registry<T>& registry, const char* kind, Args&&... args)
	{
		DispatchScope scope(dispatch_depth_);

		// first space separated word, compared without splitting the whole message
		const TCHAR* start = *message;
		while (*start == L' ')
		{
			++start;
		}

		const TCHAR* end = start;
		while (*end != L'\0' && *end != L' ')
		{
			++end;
		}

		const auto length = static_cast<int32>(end - start);
		if (length == 0)
		{
			return false;
		}

		const auto list = registry.Snapshot();
		for (const auto& command : *list)
		{
			if (command->removed || command->command.Len() != length
				|| _wcsnicmp(start, *command->command, length) != 0)
			{
				continue;
			}

			if (Invoke(*command, kind, [&](const std::function<T>& callback) { callback(std::forward<Args>(args)...); }))
			{
				return true;
			}
		}

		return false;
	}

	__declspec(noinline) void Commands::AddChatCommand(const FString& command,
		const std::function<void(AShooterPlayerController*, FString*, EChatSendMode::Type)>&
		callback)
	{
		AddCommand(command, callback, chat_commands_, _ReturnAddress(), true);
	}

	__declspec(noinline) void Commands::AddConsoleCommand(const FString& command,
		const std::function<void(APlayerController*, FString*, bool)>& callback)
	{
		AddCommand(command, callback, console_commands_, _ReturnAddress(), true);
	}

	__declspec(noinline) void Commands::AddRconCommand(const FString& command,
		const std::function<void(RCONClientConnection*, RCONPacket*, UWorld*)>& callback)
	{
		AddCommand(command, callback, rcon_commands_, _ReturnAddress(), true);
	}

	__declspec(noinline) void Commands::AddOnTickCallback(const FString& id,
		const std::function<void(float)>& callback)
	{
		AddCommand(id, callback, on_tick_callbacks_, _ReturnAddress(), false);
	}

	__declspec(noinline) void Commands::AddOnTimerCallback(const FString& id, const std::function<void()>& callback)
	{
		AddCommand(id, callback, on_timer_callbacks_, _ReturnAddress(), false);
	}

	__declspec(noinline) void Commands::AddOnChatMessageCallback(const FString& id,
		const std::function<bool(AShooterPlayerController*, FString*,
			EChatSendMode::Type, bool, bool)>& callback)
	{
		AddCommand(id, callback, on_chat_message_callbacks_, _ReturnAddress(), false);
	}

	__declspec(noinline) bool Commands::RemoveChatCommand(const FString& command)
	{
		return RemoveCommand(command, chat_commands_, _ReturnAddress(), false);
	}

	__declspec(noinline) bool Commands::RemoveConsoleCommand(const FString& command)
	{
		return RemoveCommand(command, console_commands_, _ReturnAddress(), false);
	}

	__declspec(noinline) bool Commands::RemoveRconCommand(const FString& command)
	{
		return RemoveCommand(command, rcon_commands_, _ReturnAddress(), false);
	}

	__declspec(noinline) bool Commands::RemoveOnTickCallback(const FString& id)
	{
		return RemoveCommand(id, on_tick_callbacks_, _ReturnAddress(), true);
	}

	__declspec(noinline) bool Commands::RemoveOnTimerCallback(const FString& id)
	{
		return RemoveCommand(id, on_timer_callbacks_, _ReturnAddress(), true);
	}

	__declspec(noinline) bool Commands::RemoveOnChatMessageCallback(const FString& id)
	{
		return RemoveCommand(id, on_chat_message_callbacks_, _ReturnAddress(), true);
	}

	void Commands::RemoveModuleCommands(HMODULE module)
	{
		if (module == nullptr || module == GetApiModule())
		{
			return;
		}

		{
			std::lock_guard<std::mutex> lock(purged_mutex_);
			purged_modules_.insert(module);
		}

		RemoveModuleEntries(module, chat_commands_, "chat command");
		RemoveModuleEntries(module, console_commands_, "console command");
		RemoveModuleEntries(module, rcon_commands_, "rcon command");
		RemoveModuleEntries(module, on_tick_callbacks_, "tick callback");
		RemoveModuleEntries(module, on_timer_callbacks_, "timer callback");
		RemoveModuleEntries(module, on_chat_message_callbacks_, "chat message callback");
	}

	bool Commands::IsDispatching() const
	{
		return dispatch_depth_ > 0;
	}

	bool Commands::CheckChatCommands(AShooterPlayerController* shooter_player_controller, FString* message,
		EChatSendMode::Type mode)
	{
		return CheckCommands(*message, chat_commands_, "chat command", shooter_player_controller, message, mode);
	}

	bool Commands::CheckConsoleCommands(APlayerController* a_player_controller, FString* cmd, bool write_to_log)
	{
		return CheckCommands(*cmd, console_commands_, "console command", a_player_controller, cmd, write_to_log);
	}

	bool Commands::CheckRconCommands(RCONClientConnection* rcon_client_connection, RCONPacket* rcon_packet,
		UWorld* u_world)
	{
		return CheckCommands(rcon_packet->Body, rcon_commands_, "rcon command", rcon_client_connection, rcon_packet,
			u_world);
	}

	void Commands::CheckOnTickCallbacks(float delta_seconds)
	{
		// plugins are freed here, at the start of the frame, when no callback is running
		if (!IsDispatching())
		{
			API::PluginManager::Get().ProcessPendingPlugins();
		}

		DispatchScope scope(dispatch_depth_);

		const auto list = on_tick_callbacks_.Snapshot();
		for (const auto& data : *list)
		{
			Invoke(*data, "tick callback", [delta_seconds](const std::function<void(float)>& callback)
			{
				callback(delta_seconds);
			});
		}
	}

	void Commands::CheckOnTimerCallbacks()
	{
		DispatchScope scope(dispatch_depth_);

		const auto list = on_timer_callbacks_.Snapshot();
		for (const auto& data : *list)
		{
			Invoke(*data, "timer callback", [](const std::function<void()>& callback) { callback(); });
		}
	}

	bool Commands::CheckOnChatMessageCallbacks(
		AShooterPlayerController* player_controller,
		FString* message,
		EChatSendMode::Type mode,
		bool spam_check,
		bool command_executed)
	{
		DispatchScope scope(dispatch_depth_);

		const auto list = on_chat_message_callbacks_.Snapshot();

		bool prevent_default = false;
		for (const auto& data : *list)
		{
			Invoke(*data, "chat message callback",
			       [&](const std::function<bool(AShooterPlayerController*, FString*, EChatSendMode::Type, bool, bool)>&
			       callback)
			       {
				       prevent_default |= callback(player_controller, message, mode, spam_check, command_executed);
			       });
		}

		return prevent_default;
	}

	// Free function
	ICommands& GetCommands()
	{
		return *API::game_api->GetCommands();
	}
} // namespace ArkApi