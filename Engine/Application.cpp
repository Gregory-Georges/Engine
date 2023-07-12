#include "pch.hpp"
#include "Application.hpp"



namespace Engine
{
    Application* Application::s_instance = nullptr;



    Application::Application() :
        m_isRunning(true)
    {
        //Initialize logging
        Engine::Log::Init();

        if(s_instance != nullptr)
            ENGINE_CORE_ERROR("More than one instance of application created");
        s_instance = this;

        //Main window
        m_main_window = CreateWindow();

        //Push ImGui overlay
        #ifdef ENGINE_DEBUG
        Engine::ImGuiLayer* igl = new Engine::ImGuiLayer();
        PushOverlay(igl);
        #endif // ENGINE_DEBUG
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



    Application* Application::GetInstance()

    {
        return s_instance;
    }

    Window& Application::GetMainWindow()
    {
        return *m_main_window;
    }
}
