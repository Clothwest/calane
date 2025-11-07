#pragma once

#include <spdlog/spdlog.h>

namespace Calane
{
	class Log
	{
	public:
		static void  init();

		inline static std::shared_ptr<spdlog::logger> &getLogger() { return s_Logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

#define CL_TRACE(...)		::Calane::Log::getLogger()->trace(__VA_ARGS__)
#define CL_INFO(...)		::Calane::Log::getLogger()->info(__VA_ARGS__)
#define CL_WARN(...)		::Calane::Log::getLogger()->warn(__VA_ARGS__)
#define CL_ERROR(...)		::Calane::Log::getLogger()->error(__VA_ARGS__)
#define CL_CRITICAL(...)	::Calane::Log::getLogger()->critical(__VA_ARGS__)
