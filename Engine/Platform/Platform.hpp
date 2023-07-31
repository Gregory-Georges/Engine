#ifndef DYNAMIC_HPP_INCLUDED
#define DYNAMIC_HPP_INCLUDED



//Is already defined by the project
//#define PLATFORM_LINUX



//Macro used to make shared libraries
#ifdef PLATFORM_LINUX
    #define ENGINE_EXPORT __attribute__((visibility("default")))
    #define ENGINE_IMPORT
    #include "LinuxWindow.hpp"
#endif

#ifdef PLATFORM_WINDOWS
    #define ENGINE_EXPORT __declspec(dllexport)
    #define ENGINE_IMPORT __declspec(dllimport)
    //#include "WindowsWindow.hpp"      //Does not exist yet
#endif



#endif // DYNAMIC_HPP_INCLUDED
