#include "pch.hpp"
#include "Application.hpp"

#include "Events/ApplicationEvent.hpp"

namespace Engine
{
    void Application::Run()
    {
        EventManager em;
        std::shared_ptr<Listener> ptr = std::make_shared<Listener>([](Event* event){}, nullptr);
        em.AddListener(EventType::AppRender, ptr);
        em.QueueEvent(std::make_shared<AppRenderEvent>());
        em.PollEvents();
        while(true);
    }
}
