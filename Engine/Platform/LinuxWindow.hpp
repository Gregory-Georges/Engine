#ifndef LINUXWINDOW_HPP
#define LINUXWINDOW_HPP

#include "../Window.hpp"
#include "../GraphicsContext.hpp"



class GLFWwindow;



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
        void* GetNativeWindow() override;



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
        std::unique_ptr<GraphicsContext> m_context;
        WindowData m_data;
        static int window_count;
    };



    Window* CreateWindow();
}



#endif // LINUXWINDOW_HPP
