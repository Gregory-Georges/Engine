#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <GLFW/glfw3.h>

#include "Events/EventManager.hpp"
#include "Platform/Platform.hpp"

namespace Engine
{

    //
    // All applications inherit from application class
    //
    class Application
    {
        public:

            dynamic Application();
            dynamic virtual ~Application() = default;

            dynamic void Run();

            bool m_isRunning;
    };

    //
    //To be defined in client
    //
    dynamic Application* CreateApplication();
}

#endif // APPLICATION_HPP
