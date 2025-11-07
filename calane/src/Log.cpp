#include "clpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "Application.h"

namespace Calane
{
	std::shared_ptr<spdlog::logger> Log::s_Logger;

    void Log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_Logger = spdlog::stdout_color_mt("Calane");
		s_Logger->set_level(spdlog::level::trace);
	}
}
