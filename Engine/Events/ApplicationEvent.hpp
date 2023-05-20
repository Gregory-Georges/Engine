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
            EVENT_CLASS_CATEGORY(EventCategoryApplication);

            float GetNewX() { return new_x; }
            float GetNewY() { return new_y; }



        private:

            unsigned int new_x;
            unsigned int new_y;
    };

    class WindowCloseEvent : public Event
    {
        public :

            EVENT_CLASS_TYPE(WindowClose);
            EVENT_CLASS_CATEGORY(EventCategoryApplication);
    };

    class AppTickEvent : public Event
    {
        public:

            EVENT_CLASS_TYPE(AppTick);
            EVENT_CLASS_CATEGORY(EventCategoryApplication);
    };

    class AppUpdateEvent : public Event
    {
        public :

            EVENT_CLASS_TYPE(AppUpdate);
            EVENT_CLASS_CATEGORY(EventCategoryApplication);
    };

    class AppRenderEvent : public Event
    {
        public:

            EVENT_CLASS_TYPE(AppRender);
            EVENT_CLASS_CATEGORY(EventCategoryApplication);
    };
}



#endif // APPLICATIONEVENT_HPP_INCLUDED
