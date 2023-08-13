#include "Engine/pch.hpp"
#include "Engine/Application.hpp"

#include "Engine/ImGuiLayer.hpp"
#include "Engine/Input.hpp"

#include "Engine/Renderer/Renderer.hpp"
#include "Engine/Renderer/RenderCommand.hpp"

#include "Engine/Core/Timestep.hpp"



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
        //Get delta time
        float time = (float)glfwGetTime();              //<This code should be in platform
        Timestep timestep = time - m_lastFrameTime;
        m_lastFrameTime = time;

        //Event handling
        PollEvents();

        //Update layers
        for(Layer* layer : m_layer_stack)
            layer->OnUpdate(timestep);

        //Draw  layers
        for(Layer* layer : m_layer_stack)
            layer->OnRender();

        //Draw ImGui
        #ifdef ENGINE_DEBUG
        for(Layer* layer : m_layer_stack)
            layer->OnImGuiRender();
        #endif // ENGINE_DEBUG



        //Update window
        m_main_window->OnUpdate();
    }




    void Application::PollEvents()
    {
        glfwPollEvents();

        int queue_count = m_EventQueue.size();

        for(int i = 0; i < queue_count; ++i)
        {
            for(auto it = m_layer_stack.rbegin(); it < m_layer_stack.rend(); ++it)
            {
                if(m_EventQueue.front()->m_handled)
                    break;
                (*it)->OnEvent(m_EventQueue.front());
            }

            delete m_EventQueue.front();
            m_EventQueue.pop();
        }
    }
}
