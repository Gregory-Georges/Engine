#ifndef LINUXWINDOW_HPP
#define LINUXWINDOW_HPP

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "../Events/EventManager.hpp"
#include "../Events/ApplicationEvent.hpp"
#include "../Events/KeyEvent.hpp"
#include "../Events/MouseEvent.hpp"
#include "../Window.hpp"
#include "../Log.hpp"



namespace Engine
{

    class LinuxWindow : public Window
    {
    public:

        LinuxWindow(const WindowProps& wp);
        ~LinuxWindow();

        void OnUpdate() override;

        unsigned int GetWidth() override;
        unsigned int GetHeight() override;

        void SetVSync(bool enabled) override;
        bool IsVSync() override;

        //More stuff
        void* GetNativeWindow();



    private:

        void Init(const WindowProps& wp);
        void Shutdown();


        struct WindowData
        {
            std::string Title;
            int Width, Height;
            bool VSync;
        };

        GLFWwindow* m_Window;
        WindowData m_data;
        static int window_count;
    };



    Window* CreateWindow();
}



#endif // LINUXWINDOW_HPP
