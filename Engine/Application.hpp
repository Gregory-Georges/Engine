#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <queue>

#include "Log.hpp"
#include "LayerStack.hpp"
#include "Engine/Renderer/Shader.hpp"
#include "Engine/Renderer/Buffer.hpp"
#include "Engine/Renderer/VertexArray.hpp"
#include "Engine/Renderer/OrthographicCamera.hpp"

#include "Platform/Platform.hpp"



namespace Engine
{

    //
    // All applications inherit from application class
    //
    class Application
    {
        public:

            Application();
            virtual ~Application() { delete m_main_window; }

            void Run();

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlay);

            static Application* GetInstance();

            Window& GetMainWindow();
            bool m_isRunning;

            void SendEvent(Event* event);

        private:

            static Application* s_instance;
            Window* m_main_window;
            LayerStack m_layer_stack;

            #ifdef ENGINE_DEBUG
            Layer* m_ImGuiLayer;
            #endif // ENGINE_DEBUG

            std::queue<Event*> m_EventQueue;
            void PollEvents();

            //Draw a triangle code
            OrthographicCamera m_OrthographicCamera;
            std::shared_ptr<VertexBuffer> VBO;
            std::shared_ptr<IndexBuffer> IBO;
            std::shared_ptr<VertexArray> VAO;
            std::shared_ptr<Shader> SHD;
    };



    //
    //To be defined in window subclass
    //
    Window* CreateWindow();

    //
    //To be defined in client
    //
    Application* CreateApplication();
}

#endif // APPLICATION_HPP


