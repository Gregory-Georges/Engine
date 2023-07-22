#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED

#include <string>



namespace Engine
{
    enum EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };



    #define EVENT_TYPE(x)\
        static EventType GetStaticType() { return EventType::x; }\
        EventType GetEventType() override { return EventType::x; }\
        std::string GetEventName() override { return #x; }



    class Event
    {
    public:
        Event() : m_handled(false) {}
        virtual ~Event() = default;

        //Event type function
        virtual EventType GetEventType() = 0;
        virtual std::string GetEventName() = 0;

        bool m_handled;
    };






    class EventDispatcher
    {
    public:

        EventDispatcher(Event& event) : m_Event(event)
        {

        }

        // F will be deduced by the compiler
        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_handled |= func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };
}



#define ENGINE_POLL_EVENTS()
#define ENGINE_SEND_EVENT(Event, contructor_data...)



#endif // EVENT_HPP_INCLUDED
