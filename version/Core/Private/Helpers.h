#pragma once

#include <string>
#include <vector>
#include <windows.h>

#include "json.hpp"

namespace API
{
	void MergePdbConfig(nlohmann::json& left, const nlohmann::json& right);
	std::vector<std::string> MergeStringArrays(std::vector<std::string> first, std::vector<std::string> second);

	std::string ReplaceString(std::string subject, const std::string& search, const std::string& replace);

	/**
	 * \brief Reads the "settings" object of config.json. Never throws, returns an empty object on any problem.
	 * \param error Receives a description of the problem, if any
	 */
	nlohmann::json ReadSettings(std::string* error = nullptr);

	bool GetSettingBool(const nlohmann::json& settings, const char* key, bool default_value);
	int GetSettingInt(const nlohmann::json& settings, const char* key, int default_value);
	std::string GetSettingString(const nlohmann::json& settings, const char* key, const std::string& default_value);

	HMODULE GetModuleFromAddress(const void* address);
	std::string GetModuleName(HMODULE module);
	bool IsModuleOnStack(HMODULE module);
} // namespace API
