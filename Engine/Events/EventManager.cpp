#include "pch.hpp"
#include "EventManager.hpp"

namespace Engine
{
    void EventManager::AddListener(EventType et, std::shared_ptr<Listener> li)
    {
        if(mListeners.find(et) == mListeners.end())
            mListeners.insert({et, std::list<std::shared_ptr<Listener>>()});
        mListeners[et].push_back(li);
    }

    void EventManager::RemoveListener(EventType et, void* owner)
    {
        std::list<std::shared_ptr<Listener>> ref = mListeners[et];

        int list_size = ref.size();
        for(auto i = ref.begin(); i != ref.end(); ++i)
        {
            Listener* elem = i->get();
            if(elem->GetOwner() == owner)
            {
                ref.erase(i);
                --i;
            }
        }
    }

    void EventManager::RemoveListener(void* owner)
    {
        for(auto& pair : mListeners)
            RemoveListener(pair.first, owner);
    }

    void EventManager::ClearListeners(EventType et)
    {
        //If the list doesn't exist, discard
        if(mListeners.find(et) == mListeners.end())
            return;

        std::list<std::shared_ptr<Listener>>& target_list = mListeners[et];
        target_list.clear();
    }

    void EventManager::ClearListeners()
    {
        mListeners.clear();
    }



    void EventManager::QueueEvent(std::shared_ptr<Event> event)
    {
        mEventQueue.push(event);
    }

    void EventManager::PollEvents()
    {
        int queue_size = mEventQueue.size();
        for(int i = 0; i < queue_size; ++i)
        {
            std::shared_ptr<Event> ev = mEventQueue.front();
            std::list<std::shared_ptr<Listener>> target_list = mListeners[ev->GetEventType()];
            for(std::shared_ptr<Listener>& listener : target_list)
                listener->OnEvent(ev.get());
            mEventQueue.pop();
        }
    }

    void EventManager::ClearEvents()
    {
        mEventQueue = std::queue<std::shared_ptr<Event>>();
    }
}
