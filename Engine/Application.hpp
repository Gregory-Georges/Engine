#ifndef APPLICATION_HPP
#define APPLICATION_HPP

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

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlay);

            static Application* GetInstance();

            Window& GetMainWindow();
            bool m_isRunning;

        private:

            static Application* s_instance;
            Window* m_main_window;
            LayerStack m_layer_stack;

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
    dynamic Application* CreateApplication();
}

#endif // APPLICATION_HPP


