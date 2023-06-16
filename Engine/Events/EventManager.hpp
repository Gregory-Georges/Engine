#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <queue>
#include <memory>

#include "../Platform/Platform.hpp"
#include "Event.hpp"
#include "Listener.hpp"
#include "Dispatcher.hpp"


namespace Engine
{
    class EventManager
    {
        public:

            //Singleton function
            dynamic static EventManager* Get();

            //Listener management
            template<typename E> dynamic void AddListener(ID key, std::shared_ptr<void> listener);
            template<typename E> dynamic void RemoveListener(ID key);
            dynamic void ListenerDeleted(ID key);



            //Event management
            dynamic void QueueEvent(std::shared_ptr<Event> event);
            dynamic void PollEvents();
            dynamic void ClearEvents();



        private:

            //Constructor
            EventManager() = default;

            //Checker function
            template<typename E> bool IsEventRegistered();
            template<typename E> bool IsEventEmpty();



            //Members
            std::queue<std::shared_ptr<Event>> m_events;
            std::unordered_map<EventType, std::shared_ptr<IDispatcher>> m_dispatchers;
    };
}






/////////////////////////////////////////////////////////////////
//Event macros
/////////////////////////////////////////////////////////////////

#define SEND_EVENT(EVENT_TYPE, CONSTRUCTOR_ARGS...)         Engine::EventManager::Get()->QueueEvent(std::make_shared<EVENT_TYPE>(CONSTRUCTOR_ARGS))
#define POLL_EVENTS()                                       Engine::EventManager::Get()->PollEvents()
#define ADD_LISTENER(EVENT_TYPE, ACTOR, ID)                 Engine::EventManager::Get()->AddListener<EVENT_TYPE>(ID, std::make_shared<Listener<EVENT_TYPE>>([&ACTOR](EVENT_TYPE et){ return ACTOR.On ## EVENT_TYPE(et); }))
#define ERASE_LISTENER(EVENT_TYPE, ID)                      Engine::EventManager::Get()->RemoveListener<EVENT_TYPE>(ID)
#define LISTENER_DELETED(ID)                                Engine::EventManager::Get()->ListenerDeleted(ID)



#endif // EVENTMANAGER_HPP
