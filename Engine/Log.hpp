#ifndef LOG_HPP
#define LOG_HPP

#include <memory>
#include <spdlog/spdlog.h>



namespace Engine
{
    class Log
    {
    public:

        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return mCore_logger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return mClient_logger; }



    private:

        Log() {}
        static std::shared_ptr<spdlog::logger> mCore_logger;
        static std::shared_ptr<spdlog::logger> mClient_logger;
    };

}



/*
DO NOT INCLUDE MACRO CHECK IN GENERAL USAGE - ALREADY DEFINED HERE
*/

#ifdef ENGINE_DEBUG

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






#else

//Core macros for logging
#define ENGINE_CORE_ERROR(x)
#define ENGINE_CORE_INFO(x)
#define ENGINE_CORE_WARN(x)
#define ENGINE_CORE_TRACE(x)
#define ENGINE_CORE_FATAL(x)

//Client macros for logging
#define ENGINE_ERROR(x)
#define ENGINE_INFO(x)
#define ENGINE_WARN(x)
#define ENGINE_TRACE(x)
#define ENGINE_FATAL(x)

#endif // ENGINE_DEBUG






#endif // LOG_HPP
