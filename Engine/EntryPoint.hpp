#ifndef ENTRYPOINT_HPP_INCLUDED
#define ENTRYPOINT_HPP_INCLUDED

#include "Application.hpp"
#include "Log.hpp"



//Defined in client
extern Engine::Application* Engine::CreateApplication();



//
// Main
//
int main()
{
    Engine::Log::Init();
    ENGINE_CORE_TRACE("Hello");

    auto* app = Engine::CreateApplication();
    app->Run();
    delete app;
}



#endif // ENTRYPOINT_HPP_INCLUDED
