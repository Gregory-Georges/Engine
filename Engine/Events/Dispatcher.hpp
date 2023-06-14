#ifndef DISPATCHER_HPP_INCLUDED
#define DISPATCHER_HPP_INCLUDED

#include <memory>
#include <map>

#include "Event.hpp"



using ID = uint32_t;



class IDispatcher
{
public:
    virtual ~IDispatcher() = default;

    virtual void Dispatch(Event* e) = 0;
    virtual void AddListener(ID key, std::shared_ptr<void> lis) = 0;
    virtual void RemoveListener(ID key) = 0;
    virtual bool IsEmpty() = 0;
};



//Template E is the event type
template<typename E>
class Dispatcher : public IDispatcher
{
public:

    Dispatcher() = default;
    ~Dispatcher() = default;
    void Dispatch(Event* e) override;
    void AddListener(ID key, std::shared_ptr<void> lis) override;
    void RemoveListener(ID key) override;
    bool IsEmpty() override;



private:

    std::multimap<ID, std::shared_ptr<Listener<E>>> m_listeners;
};














template<typename E> void Dispatcher<E>::Dispatch(Event* e)
{
    E* event = (E*)(e);
    for(auto& pair : m_listeners)
        pair.second->Run(*event);
}

template<typename E> void Dispatcher<E>::AddListener(ID key, std::shared_ptr<void> lis)
{
    std::shared_ptr<Listener<E>> li = std::reinterpret_pointer_cast<Listener<E>>(lis);
    m_listeners.insert({key, li});
}

template<typename E> void Dispatcher<E>::RemoveListener(ID key)
{
    m_listeners.erase(key);
}

template<typename E> bool Dispatcher<E>::IsEmpty()
{
    return m_listeners.size() > 0;
}



#endif // DISPATCHER_HPP_INCLUDED
