#include "../Engine/Engine.hpp"



class Sandbox : public Engine::Application
{
public:

    Sandbox()
    {
        m_window = new Engine::LinuxWindow(Engine::WindowProps());
    }

    ~Sandbox()
    {
        delete m_window;
    }

    Engine::Window* m_window;
};

Engine::Application* Engine::CreateApplication()
{
    Engine::Log::Init();

    return new Sandbox();
}
