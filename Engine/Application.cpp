#include "Engine/pch.hpp"
#include "Engine/Application.hpp"

#include "Engine/Platform/OpenGL/GLHeaders.hpp"

#include "Engine/ImGuiLayer.hpp"
#include "Engine/Input.hpp"



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



        //Init a triangle
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &IBO);
        glGenBuffers(1, &VBO);

        //Fill buffers wit data
        float vertices[] =
        {
            -0.5, -0.5,  0.0,
             0.0,  0.5,  0.0,
             0.5, -0.5,  0.0
        };

        unsigned int indices[] =
        {
            0, 1, 2
        };

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
        glEnableVertexAttribArray(0);
        glBindVertexArray(0);



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
        PollEvents();

        //Draw layers
        for(Layer* layer : m_layer_stack)
            layer->OnRender();

        //Draw ImGui
        #ifdef ENGINE_DEBUG
        for(Layer* layer : m_layer_stack)
            layer->OnImGuiRender();
        #endif // ENGINE_DEBUG



        //Draw test triangle
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
        glBindVertexArray(0);



        //Update window
        m_main_window->OnUpdate();
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



    void Application::SendEvent(Event* event)
    {
        m_EventQueue.push(event);
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
