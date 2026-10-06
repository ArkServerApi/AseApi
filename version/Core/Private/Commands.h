#pragma once

#include <ICommands.h>

#include <algorithm>
#include <atomic>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

namespace ArkApi
{
	class Commands : public ICommands
	{
	public:
		Commands() = default;

		Commands(const Commands&) = delete;
		Commands(Commands&&) = delete;
		Commands& operator=(const Commands&) = delete;
		Commands& operator=(Commands&&) = delete;

		~Commands() override = default;

		void AddChatCommand(const FString& command,
		                    const std::function<void(AShooterPlayerController*, FString*, EChatSendMode::Type)>&
		                    callback) override;
		void AddConsoleCommand(const FString& command,
		                       const std::function<void(APlayerController*, FString*, bool)>& callback) override;
		void AddRconCommand(const FString& command,
		                    const std::function<void(RCONClientConnection*, RCONPacket*, UWorld*)>& callback) override;

		void AddOnTickCallback(const FString& id, const std::function<void(float)>& callback) override;
		void AddOnTimerCallback(const FString& id, const std::function<void()>& callback) override;
		void AddOnChatMessageCallback(const FString& id,
		                              const std::function<bool(AShooterPlayerController*, FString*, EChatSendMode::Type,
		                                                       bool, bool)>& callback) override;

		bool RemoveChatCommand(const FString& command) override;
		bool RemoveConsoleCommand(const FString& command) override;
		bool RemoveRconCommand(const FString& command) override;

		bool RemoveOnTickCallback(const FString& id) override;
		bool RemoveOnTimerCallback(const FString& id) override;
		bool RemoveOnChatMessageCallback(const FString& id) override;

		bool CheckChatCommands(AShooterPlayerController* shooter_player_controller, FString* message,
		                       EChatSendMode::Type mode);
		bool CheckConsoleCommands(APlayerController* a_player_controller, FString* cmd, bool write_to_log);
		bool CheckRconCommands(RCONClientConnection* rcon_client_connection, RCONPacket* rcon_packet,
		                       UWorld* u_world);
		void CheckOnTickCallbacks(float delta_seconds);
		void CheckOnTimerCallbacks();
		bool CheckOnChatMessageCallbacks(AShooterPlayerController* player_controller, FString* message,
		                                 EChatSendMode::Type mode, bool spam_check, bool command_executed);

		/**
		 * \brief Removes every command and callback registered by the given module
		 */
		void RemoveModuleCommands(HMODULE module);

		/**
		 * \brief True while any command or callback is being dispatched
		 */
		bool IsDispatching() const;

	private:
		template <typename T>
		struct Command
		{
			Command(FString command, std::function<T> callback, HMODULE owner, std::string owner_name)
				: command(std::move(command)),
				  callback(std::move(callback)),
				  owner(owner),
				  owner_name(std::move(owner_name))
			{
			}

			FString command;
			std::function<T> callback;
			HMODULE owner;
			std::string owner_name;
			std::atomic<bool> removed{false};
			std::atomic<int> running{0};
		};

		// copy on write, dispatch iterates a snapshot so callbacks may add or remove entries
		template <typename T>
		class Registry
		{
		public:
			using Entry = Command<T>;
			using List = std::vector<std::shared_ptr<Entry>>;

			std::shared_ptr<const List> Snapshot() const
			{
				std::lock_guard<std::mutex> lock(mutex_);
				return list_;
			}

			void Add(std::shared_ptr<Entry> entry)
			{
				std::lock_guard<std::mutex> lock(mutex_);

				auto list = std::make_shared<List>(*list_);
				list->push_back(std::move(entry));
				list_ = std::move(list);
			}

			template <typename Pred>
			std::vector<std::shared_ptr<Entry>> RemoveIf(Pred pred)
			{
				std::vector<std::shared_ptr<Entry>> removed = RemoveIfLocked(pred);

				// release the callback now unless it is running
				for (const auto& entry : removed)
				{
					if (entry->running == 0)
					{
						entry->callback = nullptr;
					}
				}

				return removed;
			}

		private:
			template <typename Pred>
			std::vector<std::shared_ptr<Entry>> RemoveIfLocked(Pred pred)
			{
				std::vector<std::shared_ptr<Entry>> removed;

				std::lock_guard<std::mutex> lock(mutex_);

				auto list = std::make_shared<List>();
				list->reserve(list_->size());

				for (const auto& entry : *list_)
				{
					if (pred(entry))
					{
						entry->removed = true;
						removed.push_back(entry);
					}
					else
					{
						list->push_back(entry);
					}
				}

				if (!removed.empty())
				{
					list_ = std::move(list);
				}

				return removed;
			}

			mutable std::mutex mutex_;
			std::shared_ptr<const List> list_{std::make_shared<List>()};
		};

		using ChatCommand = Command<void(AShooterPlayerController*, FString*, EChatSendMode::Type)>;
		using ConsoleCommand = Command<void(APlayerController*, FString*, bool)>;
		using RconCommand = Command<void(RCONClientConnection*, RCONPacket*, UWorld*)>;

		using OnTickCallback = Command<void(float)>;
		using OnTimerCallback = Command<void()>;
		using OnChatMessageCallback = Command<bool
			(AShooterPlayerController*, FString*, EChatSendMode::Type, bool, bool)>;

		template <typename T>
		void AddCommand(const FString& command, const std::function<T>& callback, Registry<T>& registry,
		                void* return_address, bool unique_name);

		template <typename T>
		bool RemoveCommand(const FString& command, Registry<T>& registry, void* return_address, bool protect_api);

		template <typename T>
		void RemoveModuleEntries(HMODULE module, Registry<T>& registry, const char* kind);

		template <typename T, typename Fn>
		static bool Invoke(Command<T>& entry, const char* kind, Fn&& call);

		template <typename T, typename... Args>
		bool CheckCommands(const FString& message, const Registry<T>& registry, const char* kind, Args&&... args);

		class DispatchScope
		{
		public:
			explicit DispatchScope(std::atomic<int>& depth) : depth_(depth) { ++depth_; }
			~DispatchScope() { --depth_; }

			DispatchScope(const DispatchScope&) = delete;
			DispatchScope& operator=(const DispatchScope&) = delete;

		private:
			std::atomic<int>& depth_;
		};

		Registry<void(AShooterPlayerController*, FString*, EChatSendMode::Type)> chat_commands_;
		Registry<void(APlayerController*, FString*, bool)> console_commands_;
		Registry<void(RCONClientConnection*, RCONPacket*, UWorld*)> rcon_commands_;

		Registry<void(float)> on_tick_callbacks_;
		Registry<void()> on_timer_callbacks_;
		Registry<bool(AShooterPlayerController*, FString*, EChatSendMode::Type, bool, bool)> on_chat_message_callbacks_;

		std::atomic<int> dispatch_depth_{0};

		// purged at unload, their late Remove* calls (DllMain) must not hit other plugins
		std::mutex purged_mutex_;
		std::unordered_set<HMODULE> purged_modules_;
	};
} // namespace ArkApi
