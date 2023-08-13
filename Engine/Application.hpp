#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <queue>

#include "Log.hpp"
#include "LayerStack.hpp"

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

            inline void PushLayer(Layer* layer) { m_layer_stack.PushLayer(layer); }
            inline void PushOverlay(Layer* overlay) { m_layer_stack.PushOverlay(overlay); }

            inline static Application* GetInstance() { return s_instance; }

            inline Window& GetMainWindow() { return *m_main_window; }
            bool m_isRunning;

            inline void SendEvent(Event* event) { m_EventQueue.push(event); }

        private:

            std::queue<Event*> m_EventQueue;
            void PollEvents();

        private:

            static Application* s_instance;
            Window* m_main_window;
            LayerStack m_layer_stack;
            float m_lastFrameTime = 0.0f;

            #ifdef ENGINE_DEBUG
            Layer* m_ImGuiLayer;
            #endif // ENGINE_DEBUG
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


