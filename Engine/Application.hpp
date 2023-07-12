#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "Log.hpp"
#include "Events/EventManager.hpp"
#include "Platform/Platform.hpp"
#include "LayerStack.hpp"
#include "ImGuiLayer.hpp"



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

            bool m_isRunning;

        private:

            Window* m_main_window;
            LayerStack m_layer_stack;
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


