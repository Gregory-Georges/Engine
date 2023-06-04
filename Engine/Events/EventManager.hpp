#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <unordered_map>
#include <list>
#include <memory>
#include <queue>

#include "Event.hpp"
#include "Listener.hpp"


namespace Engine
{
    class EventManager
    {
    public:

        void AddListener(EventType et, std::shared_ptr<Listener>);
        void RemoveListener(EventType et, void* owner);
        void RemoveListener(void* owner);
        void ClearListeners(EventType et);
        void ClearListeners();

        void QueueEvent(std::shared_ptr<Event> event);
        void PollEvents();
        void ClearEvents();



    private:

        std::unordered_map<EventType, std::list<std::shared_ptr<Listener>>> mListeners;
        std::queue<std::shared_ptr<Event>> mEventQueue;
    };
}

#endif // EVENTMANAGER_HPP
