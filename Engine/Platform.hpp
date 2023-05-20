#ifndef DYNAMIC_HPP_INCLUDED
#define DYNAMIC_HPP_INCLUDED



//Is already defined by the project
//#define PLATFORM_LINUX



//Macro used to make shared libraries
#ifdef PLATFORM_LINUX
    #define dynamic __attribute__((visibility("default")))
#endif

#ifdef PLATFORM_WINDOWS
    #define dynamic __declspec(dllexport)
#endif



#endif // DYNAMIC_HPP_INCLUDED
