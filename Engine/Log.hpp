#ifndef LOG_HPP
#define LOG_HPP

#include "pch.hpp"

#include "Platform/Platform.hpp"
#include "Debug.hpp"


namespace Engine
{
/*******************************************************
After get logger function, the error functions can be :
- warn
- info
as in Log::GetCoreLogger()->info("msg");
*******************************************************/
    class Log
    {
        public:

            dynamic static void Init();
            dynamic inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return mCore_logger; }
            dynamic inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return mClient_logger; }



        private:

            static std::shared_ptr<spdlog::logger> mCore_logger;
            static std::shared_ptr<spdlog::logger> mClient_logger;
    };

}



//Core macros for logging
#define ENGINE_CORE_ERROR(x)  Engine::Log::GetCoreLogger()->error(x)
#define ENGINE_CORE_INFO(x)   Engine::Log::GetCoreLogger()->info(x)
#define ENGINE_CORE_WARN(x)   Engine::Log::GetCoreLogger()->warn(x)
#define ENGINE_CORE_TRACE(x)  Engine::Log::GetCoreLogger()->trace(x)
#define ENGINE_CORE_FATAL(x)  Engine::Log::GetCoreLogger()->fatal(x)

//Client macros for logging
#define ENGINE_ERROR(x)       Engine::Log::GetClientLogger()->error(x)
#define ENGINE_INFO(x)        Engine::Log::GetClientLogger()->info(x)
#define ENGINE_WARN(x)        Engine::Log::GetClientLogger()->warn(x)
#define ENGINE_TRACE(x)       Engine::Log::GetClientLogger()->trace(x)
#define ENGINE_FATAL(x)       Engine::Log::GetClientLogger()->fatal(x)

#endif // LOG_HPP
