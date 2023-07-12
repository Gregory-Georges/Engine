#include "pch.hpp"
#include "Application.hpp"



namespace Engine
{
    Application::Application() :
        m_isRunning(true)
    {
        Engine::Log::Init();

        //Main window
        m_main_window = CreateWindow();

        //Push ImGui overlay
        Engine::ImGuiLayer* igl = new Engine::ImGuiLayer();
        PushOverlay(igl);
    }



    void Application::Run()
    {
        glfwPollEvents();
        POLL_EVENTS();
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
