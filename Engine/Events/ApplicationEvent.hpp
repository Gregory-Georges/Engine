#ifndef APPLICATIONEVENT_HPP_INCLUDED
#define APPLICATIONEVENT_HPP_INCLUDED

#include "Event.hpp"



namespace Engine
{
    class WindowResizeEvent : public Event
    {
        public:

            WindowResizeEvent(float x, float y) : new_x(x), new_y(y) {}
            EVENT_CLASS_TYPE(WindowResize);

            unsigned int GetNewX() { return new_x; }
            unsigned int GetNewY() { return new_y; }



        private:

            unsigned int new_x;
            unsigned int new_y;
    };

    class WindowCloseEvent : public Event
    {
        public :

            EVENT_CLASS_TYPE(WindowClose);
    };

    class AppTickEvent : public Event
    {
        public:

            EVENT_CLASS_TYPE(AppTick);
    };

    class AppUpdateEvent : public Event
    {
        public :

            EVENT_CLASS_TYPE(AppUpdate);
    };

    class AppRenderEvent : public Event
    {
        public:

            EVENT_CLASS_TYPE(AppRender);
    };
}



#endif // APPLICATIONEVENT_HPP_INCLUDED
