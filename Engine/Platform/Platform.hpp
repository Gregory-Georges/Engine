#ifndef DYNAMIC_HPP_INCLUDED
#define DYNAMIC_HPP_INCLUDED



//Is already defined by the project
//#define PLATFORM_LINUX



//Macro used to make shared libraries
#ifdef PLATFORM_LINUX
    #define ENGINE_EXPORT __attribute__((visibility("default")))
    #define ENGINE_IMPORT

    #include "GLFW/GLFWWindow.hpp"
#endif

#ifdef PLATFORM_WINDOWS
    #define ENGINE_EXPORT __declspec(dllexport)
    #define ENGINE_IMPORT __declspec(dllimport)
#endif





namespace Engine
{
    enum class PlatformType
    {
        //Operating systems
        WINDOWS,
        LINUX,
        MAC,

        //Context libraries
        GLFW,

        //OpenGL interpreters
        GLAD,
        GLEW,

        //Rendering APIs
        OpenGL,
        Metal,
        DirectX,
        Vulkan,
    };
}






#endif // DYNAMIC_HPP_INCLUDED
