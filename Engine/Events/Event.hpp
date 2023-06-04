#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED

#include "../Platform/Platform.hpp"
#include "../Core.hpp"



namespace Engine
{
    //Contains a list of different events that can occurs
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }


    class Event
    {
        public:
            virtual ~Event() = default;
            bool handled = false;

            //Methods are defined in macros
            virtual EventType GetEventType() const = 0;
            virtual const char* GetName() const = 0;
            virtual std::string ToString() const { return GetName(); }
    };
}



#endif // EVENT_HPP_INCLUDED
