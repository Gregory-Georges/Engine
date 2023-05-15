#ifndef ENTRYPOINT_HPP_INCLUDED
#define ENTRYPOINT_HPP_INCLUDED

#include "Application.hpp"



//Defined in client
extern Engine::Application* Engine::CreateApplication();



//
// Main
//
int main()
{
    auto* app = Engine::CreateApplication();
    app->Run();
    delete app;
}



#endif // ENTRYPOINT_HPP_INCLUDED
