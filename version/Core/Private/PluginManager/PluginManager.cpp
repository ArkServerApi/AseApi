#include "PluginManager.h"

#include <fstream>
#include <functional>
#include <sstream>
#include <unordered_set>

#include <Logger/Logger.h>
#include <Tools.h>

#include "../Commands.h"
#include "../Helpers.h"
#include "../Hooks.h"
#include "../IBaseApi.h"

namespace API
{
	PluginManager& PluginManager::Get()
	{
		static PluginManager instance;
		return instance;
	}

	nlohmann::json PluginManager::GetAllPDBConfigs()
	{
		namespace fs = std::filesystem;

		const std::string dir_path = GetPluginsDir();

		auto result = nlohmann::json({});

		for (const auto& dir_name : fs::directory_iterator(dir_path))
		{
			const auto& path = dir_name.path();
			const auto filename = path.filename().stem().generic_string();

			try
			{
				const auto plugin_pdb_config = ReadPluginPDBConfig(filename);
				MergePdbConfig(result, plugin_pdb_config);
			}
			catch (const std::exception& error)
			{
				Log::GetLog()->warn("({}) {}", __FUNCTION__, error.what());
			}
		}

		return result;
	}

	nlohmann::json PluginManager::ReadPluginPDBConfig(const std::string& plugin_name)
	{
		namespace fs = std::filesystem;

		auto plugin_pdb_config = nlohmann::json({});

		const std::string dir_path = GetPluginsDir() + "/" + plugin_name;
		const std::string config_path = dir_path + "/PdbConfig.json";

		if (!fs::exists(config_path))
		{
			return plugin_pdb_config;
		}

		std::ifstream file{config_path};
		if (file.is_open())
		{
			file >> plugin_pdb_config;
			file.close();
		}

		return plugin_pdb_config;
	}

	std::string PluginManager::GetPluginsDir()
	{
		return Tools::GetCurrentDir() + "/" + game_api->GetApiName() + "/Plugins";
	}

	bool PluginManager::IsValidPluginName(const std::string& plugin_name)
	{
		if (plugin_name.empty() || plugin_name == "." || plugin_name.find("..") != std::string::npos)
		{
			return false;
		}

		return std::none_of(plugin_name.begin(), plugin_name.end(), [](char c)
		{
			return c == '/' || c == '\\' || c == ':' || static_cast<unsigned char>(c) < 0x20;
		});
	}

	void PluginManager::LoadAllPlugins()
	{
		namespace fs = std::filesystem;

		const std::string dir_path = GetPluginsDir();

		struct Candidate
		{
			std::string name;
			std::vector<std::string> dependencies;
		};

		std::vector<Candidate> candidates;

		std::error_code ec;
		for (fs::directory_iterator iter(dir_path, ec), end; !ec && iter != end; iter.increment(ec))
		{
			const auto& path = iter->path();

			std::error_code dir_ec;
			if (!fs::is_directory(path, dir_ec))
			{
				continue;
			}

			const auto filename = path.filename().stem().generic_string();

			const std::string dir_file_path = dir_path + "/" + filename;
			const std::string full_dll_path = dir_file_path + "/" + filename + ".dll";
			const std::string new_full_dll_path = dir_file_path + "/" + filename + ".dll.ArkApi";

			// Loads the new .dll.ArkApi if it exists on startup as well
			std::error_code copy_ec;
			if (fs::exists(new_full_dll_path, copy_ec))
			{
				if (fs::copy_file(new_full_dll_path, full_dll_path, fs::copy_options::overwrite_existing, copy_ec))
				{
					fs::remove(new_full_dll_path, copy_ec);
				}
				else
				{
					Log::GetLog()->warn("({}) Failed to copy {}: {}", __FUNCTION__, new_full_dll_path, copy_ec.message());
				}
			}

			candidates.push_back({filename, ReadPluginInfo(filename)["Dependencies"].get<std::vector<std::string>>()});
		}

		if (ec)
		{
			Log::GetLog()->error("({}) Failed to read {}: {}", __FUNCTION__, dir_path, ec.message());
		}

		// directory order, a plugin's dependencies from the folder load right before it
		const char* const function_name = __FUNCTION__;
		std::unordered_set<std::string> attempted;

		const auto load = [&](const Candidate& candidate)
		{
			attempted.insert(candidate.name);

			try
			{
				std::stringstream stream;

				std::shared_ptr<Plugin>& plugin = LoadPlugin(candidate.name);

				stream << "Loaded plugin " << (plugin->full_name.empty() ? plugin->name : plugin->full_name) << " V" <<
					plugin->version << " (" << plugin->description << ")";

				Log::GetLog()->info(stream.str());
			}
			catch (const std::exception& error)
			{
				Log::GetLog()->warn("({}) {}", function_name, error.what());
			}
		};

		std::unordered_map<std::string, const Candidate*> by_name;
		for (const auto& candidate : candidates)
		{
			by_name.emplace(candidate.name, &candidate);
		}

		std::unordered_set<std::string> visiting;
		std::function<void(const Candidate&)> load_with_dependencies = [&](const Candidate& candidate)
		{
			if (attempted.count(candidate.name) != 0)
			{
				return;
			}

			if (!visiting.insert(candidate.name).second)
			{
				Log::GetLog()->error("Plugin {} has circular dependencies, loading it anyway", candidate.name);
				return;
			}

			for (const std::string& dependency : candidate.dependencies)
			{
				const auto iter = by_name.find(dependency);
				if (iter != by_name.end())
				{
					load_with_dependencies(*iter->second);
				}
			}

			visiting.erase(candidate.name);
			load(candidate);
		};

		for (const auto& candidate : candidates)
		{
			load_with_dependencies(candidate);
		}

		CheckPluginsDependencies();

		// Set auto plugins reloading
		std::string error;
		const auto settings = ReadSettings(&error);
		if (!error.empty())
		{
			Log::GetLog()->error(error);
		}

		enable_plugin_reload_ = GetSettingBool(settings, "AutomaticPluginReloading", false);
		if (enable_plugin_reload_)
		{
			reload_sleep_seconds_ = GetSettingInt(settings, "AutomaticPluginReloadSeconds", 5);
			save_world_before_reload_ = GetSettingBool(settings, "SaveWorldBeforePluginReload", true);
		}

		Log::GetLog()->info("Loaded all plugins\n");
	}

	std::shared_ptr<Plugin>& PluginManager::LoadPlugin(const std::string& plugin_name) noexcept(false)
	{
		namespace fs = std::filesystem;

		if (!IsValidPluginName(plugin_name))
		{
			throw std::runtime_error("Invalid plugin name " + plugin_name);
		}

		const std::string dir_path = GetPluginsDir() + "/" + plugin_name;
		const std::string full_dll_path = dir_path + "/" + plugin_name + ".dll";

		std::error_code ec;
		if (!fs::exists(full_dll_path, ec))
		{
			throw std::runtime_error("Plugin " + plugin_name + " does not exist");
		}

		if (IsPluginLoaded(plugin_name))
		{
			throw std::runtime_error("Plugin " + plugin_name + " was already loaded");
		}

		// the previous instance has to be gone, otherwise LoadLibrary would hand back the old image
		for (auto iter = pending_free_.begin(); iter != pending_free_.end(); ++iter)
		{
			if (iter->name == plugin_name)
			{
				if (!TryFreeLibrary(*iter))
				{
					throw std::runtime_error("Plugin " + plugin_name + " is still unloading, try again");
				}

				pending_free_.erase(iter);
				break;
			}
		}

		auto plugin_info = ReadPluginInfo(plugin_name);

		// Check version
		const auto required_version = static_cast<float>(plugin_info["MinApiVersion"]);
		if (required_version != .0f && game_api->GetVersion() < required_version)
		{
			throw std::runtime_error("Plugin " + plugin_name + " requires newer API version!");
		}

		auto plugin = std::make_shared<Plugin>(nullptr, plugin_name, plugin_info["FullName"],
		                                       plugin_info["Description"], plugin_info["Version"],
		                                       plugin_info["MinApiVersion"],
		                                       plugin_info["Dependencies"]);

		HINSTANCE h_module = LoadLibraryA(full_dll_path.c_str());
		if (h_module == nullptr)
		{
			throw std::runtime_error(
				"Failed to load plugin - " + plugin_name + "\nError code: " + std::to_string(GetLastError()));
		}

		plugin->h_module = h_module;

		// Calls Plugin_Init (if found) after loading DLL
		// Note: DllMain callbacks during LoadLibrary is load-locked so we cannot do things like WaitForMultipleObjects on threads
		using pfnPluginInit = void(__fastcall*)();
		const auto pfn_init = reinterpret_cast<pfnPluginInit>(GetProcAddress(h_module, "Plugin_Init"));
		if (pfn_init != nullptr)
		{
			std::string init_error;

			try
			{
				pfn_init();
			}
			catch (const std::exception& error)
			{
				init_error = error.what();
			}
			catch (...)
			{
				init_error = "unknown exception";
			}

			if (!init_error.empty())
			{
				// by default the dll stays loaded
				if (GetSettingBool(ReadSettings(), "UnloadPluginOnInitFailure", false))
				{
					RemovePluginRegistrations(h_module);
					pending_free_.push_back({h_module, plugin_name});
				}

				throw std::runtime_error("Plugin_Init of " + plugin_name + " failed - " + init_error);
			}
		}

		return loaded_plugins_.emplace_back(std::move(plugin));
	}

	void PluginManager::UnloadPlugin(const std::string& plugin_name) noexcept(false)
	{
		const auto iter = FindPlugin(plugin_name);
		if (iter == loaded_plugins_.end())
		{
			throw std::runtime_error("Plugin " + plugin_name + " is not loaded");
		}

		const std::shared_ptr<Plugin> plugin = *iter;

		for (const auto& other : loaded_plugins_)
		{
			if (std::find(other->dependencies.begin(), other->dependencies.end(), plugin_name) != other->dependencies.end())
			{
				Log::GetLog()->warn("Plugin {} depends on {}, which is being unloaded", other->name, plugin_name);
			}
		}

		// Calls Plugin_Unload (if found) just before unloading DLL to let DLL gracefully clean up
		// Note: DllMain callbacks during FreeLibrary is load-locked so we cannot do things like WaitForMultipleObjects on threads
		using pfnPluginUnload = void(__fastcall*)();
		const auto pfn_unload = reinterpret_cast<pfnPluginUnload>(GetProcAddress(plugin->h_module, "Plugin_Unload"));
		if (pfn_unload != nullptr)
		{
			std::string unload_error;

			try
			{
				pfn_unload();
			}
			catch (const std::exception& error)
			{
				unload_error = error.what();
			}
			catch (...)
			{
				unload_error = "unknown exception";
			}

			// its cleanup did not finish, threads may still run in it, so it stays loaded
			if (!unload_error.empty())
			{
				throw std::runtime_error("Failed to unload plugin - " + plugin_name + ": " + unload_error);
			}
		}

		RemovePluginRegistrations(plugin->h_module);

		loaded_plugins_.erase(remove(loaded_plugins_.begin(), loaded_plugins_.end(), plugin), loaded_plugins_.end());

		// may still be on the stack, free it later
		pending_free_.push_back({plugin->h_module, plugin_name});
	}

	void PluginManager::RemovePluginRegistrations(HMODULE module)
	{
		dynamic_cast<ArkApi::Commands&>(*game_api->GetCommands()).RemoveModuleCommands(module);
		dynamic_cast<Hooks&>(*game_api->GetHooks()).RemoveModuleHooks(module);
		CancelModuleTimers(module);
		CancelModuleRequests(module);
	}

	bool PluginManager::TryFreeLibrary(const PendingFree& pending)
	{
		if (IsModuleOnStack(pending.module) || HasModuleTimerThreads(pending.module))
		{
			return false;
		}

		if (FreeLibrary(pending.module) == 0)
		{
			Log::GetLog()->error("Failed to unload plugin - {}\nError code: {}", pending.name, GetLastError());
		}
		else if (GetModuleFromAddress(pending.module) == pending.module)
		{
			Log::GetLog()->warn("Plugin {} is still loaded, another module holds a reference to it", pending.name);
		}

		return true;
	}

	bool PluginManager::IsPendingFree(const std::string& plugin_name) const
	{
		return std::any_of(pending_free_.begin(), pending_free_.end(), [&plugin_name](const PendingFree& pending)
		{
			return pending.name == plugin_name;
		});
	}

	void PluginManager::ProcessPendingPlugins()
	{
		if (pending_free_.empty() && pending_reloads_.empty())
		{
			return;
		}

		for (auto iter = pending_free_.begin(); iter != pending_free_.end();)
		{
			if (TryFreeLibrary(*iter))
			{
				iter = pending_free_.erase(iter);
				continue;
			}

			if (++iter->attempts == 1000)
			{
				Log::GetLog()->warn("Plugin {} can not be freed yet, its code is still in use", iter->name);
			}

			++iter;
		}

		const auto reloads = pending_reloads_;
		for (const auto& reload : reloads)
		{
			if (!reload.unloaded)
			{
				try
				{
					UnloadPlugin(reload.name);
				}
				catch (const std::exception& error)
				{
					Log::GetLog()->warn("({}) {}", __FUNCTION__, error.what());
					std::erase_if(pending_reloads_, [&](const PendingReload& r) { return r.name == reload.name; });
					continue;
				}

				for (auto& r : pending_reloads_)
				{
					if (r.name == reload.name)
					{
						r.unloaded = true;
					}
				}

				continue;
			}

			if (IsPendingFree(reload.name))
			{
				continue;
			}

			std::erase_if(pending_reloads_, [&](const PendingReload& r) { return r.name == reload.name; });
			RunReload(reload.name);
		}
	}

	void PluginManager::RunReload(const std::string& plugin_name)
	{
		namespace fs = std::filesystem;

		const std::string plugin_folder = GetPluginsDir() + "/" + plugin_name + "/";
		const std::string plugin_file_path = plugin_folder + plugin_name + ".dll";
		const std::string new_plugin_file_path = plugin_folder + plugin_name + ".dll.ArkApi";
		const std::string backup_file_path = plugin_folder + plugin_name + ".dll.ArkApi.bak";

		std::error_code ec;
		const bool has_backup = fs::copy_file(plugin_file_path, backup_file_path, fs::copy_options::overwrite_existing,
		                                      ec);

		if (!fs::copy_file(new_plugin_file_path, plugin_file_path, fs::copy_options::overwrite_existing, ec))
		{
			Log::GetLog()->error("Failed to replace plugin {} ({}), loading the old version", plugin_name, ec.message());
		}
		else
		{
			fs::remove(new_plugin_file_path, ec);

			try
			{
				LoadPlugin(plugin_name);
				Log::GetLog()->info("Reloaded plugin - {}", plugin_name);
				fs::remove(backup_file_path, ec);
				return;
			}
			catch (const std::exception& error)
			{
				Log::GetLog()->error("Failed to reload plugin {} - {}", plugin_name, error.what());
			}

			if (!has_backup || IsPendingFree(plugin_name)
				|| !fs::copy_file(backup_file_path, plugin_file_path, fs::copy_options::overwrite_existing, ec))
			{
				Log::GetLog()->error("Could not restore the old version of plugin {}", plugin_name);
				return;
			}

			Log::GetLog()->warn("Restored the old version of plugin {}", plugin_name);
		}

		fs::remove(backup_file_path, ec);

		try
		{
			LoadPlugin(plugin_name);
		}
		catch (const std::exception& error)
		{
			Log::GetLog()->error("Failed to load plugin {} - {}", plugin_name, error.what());
		}
	}

	nlohmann::json PluginManager::ReadPluginInfo(const std::string& plugin_name)
	{
		nlohmann::json plugin_info_result({});
		nlohmann::json plugin_info = nlohmann::json::object();

		const std::string dir_path = GetPluginsDir() + "/" + plugin_name;
		const std::string config_path = dir_path + "/PluginInfo.json";

		std::ifstream file{config_path};
		if (file.is_open())
		{
			plugin_info = nlohmann::json::parse(file, nullptr, false);
			file.close();

			if (plugin_info.is_discarded() || !plugin_info.is_object())
			{
				Log::GetLog()->warn("({}) PluginInfo.json of {} is not valid JSON", __FUNCTION__, plugin_name);
				plugin_info = nlohmann::json::object();
			}
		}

		const char* const function_name = __FUNCTION__;
		const auto read = [&](const char* key, auto default_value, auto is_type)
		{
			const auto iter = plugin_info.find(key);
			if (iter == plugin_info.end())
			{
				plugin_info_result[key] = default_value;
			}
			else if (!is_type(*iter))
			{
				Log::GetLog()->warn("({}) {} in PluginInfo.json of {} has the wrong type", function_name, key,
				                    plugin_name);
				plugin_info_result[key] = default_value;
			}
			else
			{
				plugin_info_result[key] = *iter;
			}
		};

		const auto is_string = [](const nlohmann::json& value) { return value.is_string(); };
		const auto is_number = [](const nlohmann::json& value) { return value.is_number(); };
		const auto is_string_array = [](const nlohmann::json& value)
		{
			return value.is_array() && std::all_of(value.begin(), value.end(),
			                                       [](const nlohmann::json& item) { return item.is_string(); });
		};

		read("FullName", "", is_string);
		read("Description", "No description", is_string);
		read("Version", 1.00f, is_number);
		read("MinApiVersion", .0f, is_number);
		read("Dependencies", std::vector<std::string>{}, is_string_array);

		return plugin_info_result;
	}

	void PluginManager::CheckPluginsDependencies()
	{
		for (const auto& plugin : loaded_plugins_)
		{
			if (plugin->dependencies.empty())
			{
				continue;
			}

			for (const std::string& dependency : plugin->dependencies)
			{
				if (!IsPluginLoaded(dependency))
				{
					Log::GetLog()->error("Plugin {} is  missing! {} might not work correctly", dependency,
					                     plugin->name);
				}
			}
		}
	}

	std::vector<std::shared_ptr<Plugin>>::const_iterator PluginManager::FindPlugin(const std::string& plugin_name)
	{
		const auto iter = std::find_if(loaded_plugins_.begin(), loaded_plugins_.end(),
		                               [&plugin_name](const std::shared_ptr<Plugin>& plugin) -> bool
		                               {
			                               return plugin->name == plugin_name;
		                               });

		return iter;
	}

	bool PluginManager::IsPluginLoaded(const std::string& plugin_name)
	{
		return FindPlugin(plugin_name) != loaded_plugins_.end();
	}

	void PluginManager::DetectPluginChangesTimerCallback()
	{
		auto& pluginManager = Get();

		const time_t now = time(nullptr);
		if (now < pluginManager.next_reload_check_
			|| !pluginManager.enable_plugin_reload_)
		{
			return;
		}

		pluginManager.next_reload_check_ = now + pluginManager.reload_sleep_seconds_;

		try
		{
			pluginManager.DetectPluginChanges();
		}
		catch (const std::exception& error)
		{
			Log::GetLog()->warn("({}) {}", __FUNCTION__, error.what());
		}
	}

	void PluginManager::DetectPluginChanges()
	{
		namespace fs = std::filesystem;

		// Prevents saving world multiple times if multiple plugins are queued to be reloaded
		bool save_world = save_world_before_reload_;

		const std::string plugins_dir = GetPluginsDir();

		for (const auto& plugin : loaded_plugins_)
		{
			const std::string& filename = plugin->name;
			const std::string new_plugin_file_path = plugins_dir + "/" + filename + "/" + filename + ".dll.ArkApi";

			std::error_code ec;
			const auto size = fs::file_size(new_plugin_file_path, ec);
			const auto write_time = ec ? fs::file_time_type{} : fs::last_write_time(new_plugin_file_path, ec);
			if (ec)
			{
				reload_candidates_.erase(filename);
				continue;
			}

			// only reload a file that did not change since the last check and is not open elsewhere
			const auto candidate = reload_candidates_.find(filename);
			if (candidate == reload_candidates_.end() || candidate->second.size != size
				|| candidate->second.write_time != write_time)
			{
				reload_candidates_[filename] = {size, write_time};
				continue;
			}

			const HANDLE file = CreateFileW(fs::path(new_plugin_file_path).c_str(), GENERIC_READ, 0, nullptr,
			                                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
			if (file == INVALID_HANDLE_VALUE)
			{
				continue;
			}

			CloseHandle(file);

			reload_candidates_.erase(filename);

			if (std::any_of(pending_reloads_.begin(), pending_reloads_.end(),
			                [&filename](const PendingReload& r) { return r.name == filename; }))
			{
				continue;
			}

#ifndef ATLAS_GAME // not on ATLAS
			// Save the world in case the unload/load procedure causes crash
			if (save_world)
			{
				Log::GetLog()->info("Saving world before reloading plugins ...");
				ArkApi::GetApiUtils().GetShooterGameMode()->SaveWorld(true);
				Log::GetLog()->info("World saved.");

				save_world = false; // do not save again if multiple plugins are reloaded in this loop
			}
#endif

			pending_reloads_.push_back({filename});
		}
	}
} // namespace API