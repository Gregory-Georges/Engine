#ifndef LINUXWINDOW_HPP
#define LINUXWINDOW_HPP

#include <GLFW/glfw3.h>

#include "../Window.hpp"



namespace Engine
{

    class LinuxWindow : public Window
    {
        public:

            LinuxWindow(const WindowProps& wp);
            virtual ~LinuxWindow();

            dynamic void OnUpdate() override;

            dynamic int GetWidth() override;
            dynamic int GetHeight() override;

            //Event stuff
            //dynamic void SetEventCallback(const std::function<Event&>& callback) override;
            dynamic void SetVSync(bool enabled) override;
            dynamic bool IsVSync() override;

            //More stuff
            dynamic virtual void* GetNativeWindow();



        private:

            virtual void Init(const WindowProps& props);
            virtual void Shutdown();

            GLFWwindow* m_Window;
            //Scope<GraphicsContext> m_Context;

            struct WindowData
            {
                std::string Title;
                unsigned int Width, Height;
                bool VSync;

                //EventCallbackFn callback;
            };

            WindowData m_Data;
    };
}

#endif // LINUXWINDOW_HPP
