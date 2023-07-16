#include "pch.hpp"
#include "Application.hpp"

#include "Input.hpp"



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
        m_ImGuiLayer = new Engine::ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
        #endif // ENGINE_DEBUG
    }



    void Application::Run()
    {
        //Clear display
        glClear(GL_COLOR_BUFFER_BIT);

        //Event handling
        glfwPollEvents();
        POLL_EVENTS();

        //Temporary - Need for cleanup
        m_ImGuiLayer->OnRender();
        glfwSwapBuffers((GLFWwindow*)(m_main_window->GetNativeWindow()));
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
