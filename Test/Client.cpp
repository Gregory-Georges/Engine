#include <iostream>

#include "../Engine/Engine.hpp"

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
    return new Sandbox();
}
