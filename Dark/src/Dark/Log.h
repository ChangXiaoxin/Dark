#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Dark {


    class DARK_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    };

}

// Core log macros.
#define DK_CORE_TRACE(...) ::Dark::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DK_CORE_INFO(...)  ::Dark::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DK_CORE_WARN(...)  ::Dark::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DK_CORE_ERROR(...) ::Dark::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DK_CORE_FATAL(...) ::Dark::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros.
#define DK_TRACE(...)      ::Dark::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DK_INFO(...)       ::Dark::Log::GetClientLogger()->info(__VA_ARGS__)
#define DK_WARN(...)       ::Dark::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DK_ERROR(...)      ::Dark::Log::GetClientLogger()->error(__VA_ARGS__)
#define DK_FATAL(...)      ::Dark::Log::GetClientLogger()->fatal(__VA_ARGS__)
