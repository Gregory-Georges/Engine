#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <GLFW/glfw3.h>

#include "Events/EventManager.hpp"
#include "Platform/Platform.hpp"
#include "LayerStack.hpp"

namespace Engine
{

    //
    // All applications inherit from application class
    //
    class Application
    {
        public:

            dynamic Application();
            dynamic virtual ~Application() = default;

            dynamic void Run();

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlay);

            bool m_isRunning;

        private:

            LayerStack m_layer_stack;
    };

    //
    //To be defined in client
    //
    dynamic Application* CreateApplication();
}

#endif // APPLICATION_HPP


