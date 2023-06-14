#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Platform/Platform.hpp"

namespace Engine
{

    //
    // All applications inherit from application class
    //
    class Application
    {
        public:

            dynamic Application() = default;
            dynamic virtual ~Application() = default;

            dynamic void Run();
    };

    //
    //To be defined in client
    //
    dynamic Application* CreateApplication();
}

#endif // APPLICATION_HPP
