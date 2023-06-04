#ifndef LISTENER_HPP_INCLUDED
#define LISTENER_HPP_INCLUDED

#include <functional>

#include "Event.hpp"



namespace Engine
{
    class Listener
    {
    public:
        Listener(std::function<void(Event* event)> func, void* owner) : mOnEvent(func), mOwner(owner) {}
        void OnEvent(Event* event) { mOnEvent(event); }
        void* GetOwner() { return mOwner; }

    private:
        std::function<void(Event* event)> mOnEvent;
        void* mOwner;
    };
}



#endif // LISTENER_HPP_INCLUDED
