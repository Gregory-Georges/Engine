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



    void Application::PushLayer(Layer* layer)
    {
        m_layer_stack.PushLayer(layer);
    }



    void Application::PushOverlay(Layer* overlay)
    {
        m_layer_stack.PushOverlay(overlay);
    }
}
