#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "Log.hpp"
#include "Events/EventManager.hpp"
#include "Platform/Platform.hpp"
#include "LayerStack.hpp"
#include "ImGuiLayer.hpp"
#include "Input.hpp"



namespace Engine
{

    //
    // All applications inherit from application class
    //
    class Application
    {
        public:

            dynamic Application();
            dynamic virtual ~Application() { delete m_main_window; }

            dynamic void Run();

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
            ImGuiLayer* m_ImGuiLayer;
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


