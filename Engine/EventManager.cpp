#include "pch.hpp"
#include "Events/EventManager.hpp"



/////////////////////////////////////////////////////////////////
//Singleton functions
/////////////////////////////////////////////////////////////////

Engine::EventManager* Engine::EventManager::Get()
{
    static EventManager static_em;
    return &static_em;
}



/////////////////////////////////////////////////////////////////
//Listener management
/////////////////////////////////////////////////////////////////

template<typename E>
void Engine::EventManager::AddListener(ID key, std::shared_ptr<void> listener)
{
    if(!IsEventRegistered<E>())
        m_dispatchers.insert({E::GetStaticType(), std::make_shared<Dispatcher<E>>()});

    m_dispatchers[E::GetStaticType()]->AddListener(key, listener);
}

template<typename E>
void Engine::EventManager::RemoveListener(ID key)
{
    if(!IsEventRegistered<E>())
        return;

    m_dispatchers[E::GetStaticType()]->RemoveListener(key);

    if(IsEventEmpty<E>())
        m_dispatchers.erase(E::GetStaticType());
}

void Engine::EventManager::ListenerDeleted(ID key)
{
    for(auto& dis : m_dispatchers)
        dis.second->RemoveListener(key);
}



/////////////////////////////////////////////////////////////////
//Event management
/////////////////////////////////////////////////////////////////

void Engine::EventManager::QueueEvent(std::shared_ptr<Event> event)
{
    m_events.push(event);
}

void Engine::EventManager::PollEvents()
{
    unsigned int event_size = m_events.size();
    for(unsigned int i = 0; i < event_size; ++i)
    {
        std::shared_ptr<Event> event = m_events.front();
        m_dispatchers[event->GetEventType()]->Dispatch(event.get());
        m_events.pop();
    }
}

void Engine::EventManager::ClearEvents()
{
    unsigned int event_size = m_events.size();
    for(unsigned int i = 0; i < event_size; ++i)
        m_events.pop();
}



template<typename E>
bool Engine::EventManager::IsEventRegistered()
{
    return m_dispatchers.find(E::GetStaticType()) != m_dispatchers.end();
}

template<typename E>
bool Engine::EventManager::IsEventEmpty()
{
    if(!IsEventRegistered<E>())
        return false;

    return m_dispatchers[E::GetStaticType()]->IsEmpty();
}
