#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Flare {

	class FLARE_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define FL_CORE_INFO(...) ::Flare::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FL_CORE_WARN(...) ::Flare::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FL_CORE_ERROR(...) ::Flare::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FL_CORE_TRACE(...) ::Flare::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define FL_CLIENT_INFO(...) ::Flare::Log::GetClientLogger()->info(__VA_ARGS__)
#define FL_CLIENT_WARN(...) ::Flare::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FL_CLIENT_ERROR(...) ::Flare::Log::GetClientLogger()->error(__VA_ARGS__)
#define FL_CLIENT_TRACE(...) ::Flare::Log::GetClientLogger()->trace(__VA_ARGS__)