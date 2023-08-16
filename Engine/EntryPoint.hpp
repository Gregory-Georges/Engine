#ifndef ENTRYPOINT_HPP_INCLUDED
#define ENTRYPOINT_HPP_INCLUDED

#include "Application.hpp"

#include <iostream>



//Defined in client
extern Engine::Application* Engine::CreateApplication();



//
// Main
//
int main()
{
    //Create application
    auto* app = Engine::CreateApplication();

    //Program loop
    while(app->Running())
        app->Run();

    //Cleanup
    delete app;
}



#endif // ENTRYPOINT_HPP_INCLUDED
