#include <iostream>

#include "Engine/Engine.hpp"



class Sandbox : public Engine::Application
{
    public:

        Sandbox()
        {

        }

        ~Sandbox()
        {

        }
};

Engine::Application* Engine::CreateApplication()
{
    Engine::Log::Init();
    ENGINE_INFO("Window created");

    return new Sandbox();
}
