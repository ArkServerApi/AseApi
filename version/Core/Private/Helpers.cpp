#include "Helpers.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <locale>

#include <Logger/Logger.h>
#include <Tools.h>

namespace API
{
	void MergePdbConfig(nlohmann::json& left, const nlohmann::json& right)
	{
		nlohmann::json pdb_config_result({});

		pdb_config_result["structures"] = MergeStringArrays(left.value("structures", std::vector<std::string>{}),
		                                                    right.value("structures", std::vector<std::string>{}));
		pdb_config_result["functions"] = MergeStringArrays(left.value("functions", std::vector<std::string>{}),
		                                                   right.value("functions", std::vector<std::string>{}));
		pdb_config_result["globals"] = MergeStringArrays(left.value("globals", std::vector<std::string>{}),
		                                                 right.value("globals", std::vector<std::string>{}));

		left = pdb_config_result;
	}

	std::vector<std::string> MergeStringArrays(std::vector<std::string> first, std::vector<std::string> second)
	{
		const auto less = [](const std::string& s1, const std::string& s2)
		{
			return std::lexicographical_compare(
				s1.begin(),
				s1.end(),
				s2.begin(),
				s2.end(),
				[](char c1, char c2)
				{
					return std::tolower(static_cast<unsigned char>(c1)) < std::tolower(static_cast<unsigned char>(c2));
				}
			);
		};

		const auto equal = [](const std::string& s1, const std::string& s2)
		{
			return std::equal(
				s1.begin(),
				s1.end(),
				s2.begin(),
				s2.end(),
				[](char c1, char c2)
				{
					return std::tolower(static_cast<unsigned char>(c1)) == std::tolower(static_cast<unsigned char>(c2));
				}
			);
		};

		std::vector<std::string> merged, unique;
		std::sort(first.begin(), first.end(), less);
		std::sort(second.begin(), second.end(), less);
		std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(merged), less);
		std::unique_copy(merged.begin(), merged.end(), std::back_inserter(unique), equal);

		return unique;
	}

	std::string ReplaceString(std::string subject, const std::string& search, const std::string& replace)
	{
		if (search.empty())
		{
			return subject;
		}

		size_t pos = 0;
		while ((pos = subject.find(search, pos)) != std::string::npos)
		{
			subject.replace(pos, search.length(), replace);
			pos += replace.length();
		}

		return subject;
	}

	nlohmann::json ReadSettings(std::string* error)
	{
		const std::string config_path = ArkApi::Tools::GetCurrentDir() + "/config.json";

		std::ifstream file{config_path};
		if (!file.is_open())
		{
			return nlohmann::json::object();
		}

		const nlohmann::json config = nlohmann::json::parse(file, nullptr, false);
		if (config.is_discarded() || !config.is_object())
		{
			if (error)
			{
				*error = "config.json is not valid JSON, using default settings";
			}

			return nlohmann::json::object();
		}

		const auto iter = config.find("settings");
		if (iter == config.end() || !iter->is_object())
		{
			if (error)
			{
				*error = "config.json has no \"settings\" object, using default settings";
			}

			return nlohmann::json::object();
		}

		return *iter;
	}

	namespace
	{
		void LogWrongType(const char* key)
		{
			if (Log::GetLog())
			{
				Log::GetLog()->error("config.json setting {} has the wrong type, using the default", key);
			}
		}
	}

	bool GetSettingBool(const nlohmann::json& settings, const char* key, bool default_value)
	{
		const auto iter = settings.find(key);
		if (iter == settings.end())
		{
			return default_value;
		}

		if (!iter->is_boolean())
		{
			LogWrongType(key);
			return default_value;
		}

		return iter->get<bool>();
	}

	int GetSettingInt(const nlohmann::json& settings, const char* key, int default_value)
	{
		const auto iter = settings.find(key);
		if (iter == settings.end())
		{
			return default_value;
		}

		if (!iter->is_number_integer())
		{
			LogWrongType(key);
			return default_value;
		}

		return iter->get<int>();
	}

	std::string GetSettingString(const nlohmann::json& settings, const char* key, const std::string& default_value)
	{
		const auto iter = settings.find(key);
		if (iter == settings.end())
		{
			return default_value;
		}

		if (!iter->is_string())
		{
			LogWrongType(key);
			return default_value;
		}

		return iter->get<std::string>();
	}

	HMODULE GetModuleFromAddress(const void* address)
	{
		HMODULE module = nullptr;
		if (!GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
		                        static_cast<LPCWSTR>(address), &module))
		{
			return nullptr;
		}

		return module;
	}

	std::string GetModuleName(HMODULE module)
	{
		if (module == nullptr)
		{
			return "unknown";
		}

		wchar_t buffer[MAX_PATH * 4];
		const DWORD length = GetModuleFileNameW(module, buffer, static_cast<DWORD>(std::size(buffer)));
		if (length == 0 || length >= std::size(buffer))
		{
			return "unknown";
		}

		std::wstring path(buffer, length);
		const auto slash = path.find_last_of(L"\\/");
		if (slash != std::wstring::npos)
		{
			path = path.substr(slash + 1);
		}

		const auto dot = path.find_last_of(L'.');
		if (dot != std::wstring::npos)
		{
			path = path.substr(0, dot);
		}

		return ArkApi::Tools::Utf8Encode(path);
	}

	bool IsModuleOnStack(HMODULE module)
	{
		if (module == nullptr)
		{
			return false;
		}

		const auto* base = reinterpret_cast<const BYTE*>(module);
		const auto* dos_header = reinterpret_cast<const IMAGE_DOS_HEADER*>(base);
		const auto* nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS*>(base + dos_header->e_lfanew);
		const BYTE* end = base + nt_headers->OptionalHeader.SizeOfImage;

		constexpr ULONG batch = 62;
		void* frames[batch];
		ULONG skip = 0;

		for (;;)
		{
			const USHORT captured = RtlCaptureStackBackTrace(skip, batch, frames, nullptr);
			for (USHORT i = 0; i < captured; ++i)
			{
				const auto* address = static_cast<const BYTE*>(frames[i]);
				if (address >= base && address < end)
				{
					return true;
				}
			}

			if (captured < batch || skip > 4096)
			{
				return false;
			}

			skip += captured;
		}
	}
} // namespace API
