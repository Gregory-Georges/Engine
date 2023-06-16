#ifndef APPLICATIONEVENT_HPP_INCLUDED
#define APPLICATIONEVENT_HPP_INCLUDED

#include "Event.hpp"



namespace Engine
{
    class WindowResizeEvent : public Event
    {
        public:

            WindowResizeEvent(int x, int y) : new_x(x), new_y(y) {}
            EVENT_TYPE(WindowResize);

            int GetNewX() { return new_x; }
            int GetNewY() { return new_y; }



        private:

            int new_x;
            int new_y;
    };

    class WindowCloseEvent : public Event
    {
        public :

            EVENT_TYPE(WindowClose);
    };

    class AppTickEvent : public Event
    {
        public:

            EVENT_TYPE(AppTick);
    };

    class AppUpdateEvent : public Event
    {
        public :

            EVENT_TYPE(AppUpdate);
    };

    class AppRenderEvent : public Event
    {
        public:

            EVENT_TYPE(AppRender);
    };
}



#endif // APPLICATIONEVENT_HPP_INCLUDED
