#include "Log.hpp"

namespace Engine
{
    std::shared_ptr<spdlog::logger> Log::mCore_logger;
    std::shared_ptr<spdlog::logger> Log::mClient_logger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        mCore_logger = spdlog::stdout_color_mt("Engine");
        mCore_logger->set_level(spdlog::level::trace);

        mClient_logger = spdlog::stdout_color_mt("App");
        mClient_logger->set_level(spdlog::level::trace);
    }
}
