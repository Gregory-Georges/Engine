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
        virtual ~Event() = default;

        //Event type function
        virtual EventType GetEventType() = 0;
        virtual std::string GetEventName() = 0;
    };
}



#define ENGINE_POLL_EVENTS()
#define ENGINE_SEND_EVENT(Event, contructor_data...)



#endif // EVENT_HPP_INCLUDED
