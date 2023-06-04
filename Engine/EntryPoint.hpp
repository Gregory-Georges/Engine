#ifndef ENTRYPOINT_HPP_INCLUDED
#define ENTRYPOINT_HPP_INCLUDED

#include "Events/EventManager.hpp"
#include "Application.hpp"
#include "Log.hpp"

#include "Events/EventManager.hpp"
#include "Events/ApplicationEvent.hpp"



//Defined in client
extern Engine::Application* Engine::CreateApplication();



//
// Main
//
int main()
{
    Engine::EventManager em;
    std::shared_ptr<Engine::Event> ev = std::make_shared<Engine::WindowResizeEvent>(2, 4);
    std::shared_ptr<Engine::Listener> li = std::make_shared<Engine::Listener>([](Engine::Event* e){ std::cout << e->GetName() << "\n"; }, nullptr);
    em.AddListener(Engine::EventType::WindowResize, li);
    em.QueueEvent(ev);
    em.PollEvents();

    auto* app = Engine::CreateApplication();
    app->Run();
    delete app;
}



#endif // ENTRYPOINT_HPP_INCLUDED
