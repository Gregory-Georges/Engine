#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Platform/Platform.hpp"

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
        dynamic virtual ~Window();

        dynamic virtual void OnUpdate() = 0;

        dynamic virtual int GetWidth();
        dynamic virtual int GetHeight();

        //Event stuff
        //dynamic virtual void SetEventCallback(const std::function<Event&>& callback) = 0;
        dynamic virtual void SetVSync(bool enabled) = 0;
        dynamic virtual bool IsVSync() = 0;

        dynamic static Window* Create(const WindowProps& properties = WindowProps());
    };
}

#endif // WINDOW_HPP
