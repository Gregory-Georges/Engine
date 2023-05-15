#ifndef DYNAMIC_HPP_INCLUDED
#define DYNAMIC_HPP_INCLUDED



#define PLATFORM_LINUX



//Macro used to make shared libraries
#ifdef PLATFORM_LINUX
    #define dynamic __attribute__((visibility("default")))
#endif

#ifdef PLATFORM WINDOWS
    #define dynamic __declspec(dllexport)
#endif



#endif // DYNAMIC_HPP_INCLUDED
