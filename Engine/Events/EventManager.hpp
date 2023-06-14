#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <queue>
#include <memory>

#include "Event.hpp"
#include "Listener.hpp"
#include "Dispatcher.hpp"



class EventManager
{
    public:

        //Singleton function
        static EventManager* Get();

        //Listener management
        template<typename E> void AddListener(ID key, std::shared_ptr<void> listener);
        template<typename E> void RemoveListener(ID key);
        void ListenerDeleted(ID key);



        //Event management
        void QueueEvent(std::shared_ptr<Event> event);
        void PollEvents();
        void ClearEvents();



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















/////////////////////////////////////////////////////////////////
//Singleton functions
/////////////////////////////////////////////////////////////////

EventManager* EventManager::Get()
{
    static EventManager static_em;
    return &static_em;
}



/////////////////////////////////////////////////////////////////
//Listener management
/////////////////////////////////////////////////////////////////

template<typename E>
void EventManager::AddListener(ID key, std::shared_ptr<void> listener)
{
    if(!IsEventRegistered<E>())
        m_dispatchers.insert({E::GetStaticType(), std::make_shared<Dispatcher<E>>()});

    m_dispatchers[E::GetStaticType()]->AddListener(key, listener);
}

template<typename E>
void EventManager::RemoveListener(ID key)
{
    if(!IsEventRegistered<E>())
        return;

    m_dispatchers[E::GetStaticType()]->RemoveListener(key);

    if(IsEventEmpty<E>())
        m_dispatchers.erase(E::GetStaticType());
}

void EventManager::ListenerDeleted(ID key)
{
    for(auto& dis : m_dispatchers)
        dis.second->RemoveListener(key);
}



/////////////////////////////////////////////////////////////////
//Event management
/////////////////////////////////////////////////////////////////

void EventManager::QueueEvent(std::shared_ptr<Event> event)
{
    m_events.push(event);
}

void EventManager::PollEvents()
{
    unsigned int event_size = m_events.size();
    for(unsigned int i = 0; i < event_size; ++i)
    {
        std::shared_ptr<Event> event = m_events.front();
        m_dispatchers[event->GetEventType()]->Dispatch(event.get());
        m_events.pop();
    }
}

void EventManager::ClearEvents()
{
    unsigned int event_size = m_events.size();
    for(unsigned int i = 0; i < event_size; ++i)
        m_events.pop();
}



template<typename E>
bool EventManager::IsEventRegistered()
{
    return m_dispatchers.find(E::GetStaticType()) != m_dispatchers.end();
}

template<typename E>
bool EventManager::IsEventEmpty()
{
    if(!IsEventRegistered<E>())
        return false;

    return m_dispatchers[E::GetStaticType()]->IsEmpty();
}



/////////////////////////////////////////////////////////////////
//Event macros
/////////////////////////////////////////////////////////////////

#define SEND_EVENT(EVENT_TYPE, CONSTRUCTOR_ARGS...)         EventManager::Get()->QueueEvent(std::make_shared<EVENT_TYPE>(CONSTRUCTOR_ARGS))
#define POLL_EVENTS()                                       EventManager::Get()->PollEvents()
#define ADD_LISTENER(EVENT_TYPE, ACTOR, ID)                 EventManager::Get()->AddListener<EVENT_TYPE>(ID, std::make_shared<Listener<EVENT_TYPE>>([&ACTOR](EVENT_TYPE et){ return ACTOR.On ## EVENT_TYPE(et); }))
#define ERASE_LISTENER(EVENT_TYPE, ID)                      EventManager::Get()->RemoveListener<EVENT_TYPE>(ID)
#define LISTENER_DELETED(ID)                                EventManager::Get()->ListenerDeleted(ID)



#endif // EVENTMANAGER_HPP
