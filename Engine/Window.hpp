#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Platform/Platform.hpp"
#include "Events/Event.hpp"

#include <functional>



namespace Engine
{

    struct WindowProps
    {
        std::string title;
        int width;
        int height;

        WindowProps(int width = 1280, int height = 720, std::string title = "Window") :
            title(title), width(width), height(height) {}
    };



    //using WindowCallbackFun = std::function<void(Event&)>



    class Window
    {
        virtual ~Window();

        virtual void OnUpdate() = 0;

        virtual int GetWidth();
        virtual int GetHeight();

        virtual void SetEventCallback(const std::function<void(Event*)>& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() = 0;

        static Window* Create(const WindowProps& properties = WindowProps());
    };
}

#endif // WINDOW_HPP
