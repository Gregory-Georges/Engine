#ifndef LISTENER_HPP_INCLUDED
#define LISTENER_HPP_INCLUDED

#include <memory>
#include <functional>



template<typename E>
class Listener
{
public:

    Listener(std::function<bool(E&)> func) : m_onEvent(func) {}
    bool Run(E& event) { return m_onEvent(event); }


private:

    std::function<bool(E&)> m_onEvent;
};



#endif // LISTENER_HPP_INCLUDED
