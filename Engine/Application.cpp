#include "pch.hpp"
#include "Application.hpp"

namespace Engine
{
    Application::Application() :
        m_isRunning(true)
    {

    }



    void Application::Run()
    {
        while(true)
        {
            glfwPollEvents();
            POLL_EVENTS();
        }
    }
}
