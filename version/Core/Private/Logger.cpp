#include <Logger/Logger.h>

#include <Tools.h>
#include <json.hpp>

#include "Helpers.h"

std::string GetLogName()
{
	static const std::string log_name = API::GetSettingString(API::ReadSettings(), "StaticLogPath", "");
	return log_name;
}

spdlog::level::level_enum GetLogFlushLevel()
{
	static const spdlog::level::level_enum level = API::GetSettingBool(API::ReadSettings(), "FlushLogsImmediately", true)
		                                               ? spdlog::level::info
		                                               : spdlog::level::warn;
	return level;
}

std::vector<spdlog::sink_ptr>& GetLogSinks()
{
	static std::vector<spdlog::sink_ptr> sinks{
		std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>(),
		std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
			!GetLogName().empty()
				? GetLogName()
				: spdlog::sinks::default_daily_file_name_calculator::
				calc_filename(
					API::Tools::GetCurrentDir() + "/logs/ArkApi_" + std::to_string(GetCurrentProcessId()) + ".log"),
			1024 * 1024, 5)
	};

	return sinks;
}
