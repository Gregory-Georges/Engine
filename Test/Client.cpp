#include <iostream>

#include "../Engine/Engine.hpp"



class Sandbox : public Engine::Application
{
public:

    Sandbox()
    {
        win = new Engine::LinuxWindow(Engine::WindowProps());
    }

    ~Sandbox()
    {

    }
};

Engine::Application* Engine::CreateApplication()
{
    Engine::Log::Init();

    return new Sandbox();
}
