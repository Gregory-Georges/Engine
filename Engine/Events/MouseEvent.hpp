#ifndef MOUSEEVENT_HPP_INCLUDED
#define MOUSEEVENT_HPP_INCLUDED

#include "Event.hpp"



namespace Engine
{
    class MouseMovedEvent : public Event
	{
        public:

            MouseMovedEvent(const double x, const double y) : m_MouseX(x), m_MouseY(y) {}

            double GetX() const { return m_MouseX; }
            double GetY() const { return m_MouseY; }

            EVENT_TYPE(MouseMoved);

        private:

            double m_MouseX, m_MouseY;
	};



	class MouseScrolledEvent : public Event
	{
        public:

            MouseScrolledEvent(const double xOffset, const double yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

            double GetXOffset() const { return m_XOffset; }
            double GetYOffset() const { return m_YOffset; }

            EVENT_TYPE(MouseScrolled);

        private:

            double m_XOffset, m_YOffset;
	};



	class MouseButtonEvent : public Event
	{
        public:

            MouseCode GetMouseButton() const { return m_Button; }

        protected:

            MouseButtonEvent(const MouseCode button) : m_Button(button) {}
            MouseCode m_Button;
	};



	class MouseButtonPressedEvent : public MouseButtonEvent
	{
        public:

            MouseButtonPressedEvent(const MouseCode button) : MouseButtonEvent(button) {}

            EVENT_TYPE(MouseButtonPressed);
	};



	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
        public:

            MouseButtonReleasedEvent(const MouseCode button) : MouseButtonEvent(button) {}

            EVENT_TYPE(MouseButtonReleased)
	};
}



#endif // MOUSEEVENT_HPP_INCLUDED
