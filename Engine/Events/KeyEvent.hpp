#ifndef KEYEVENT_H_INCLUDED
#define KEYEVENT_H_INCLUDED

#include "Event.hpp"
#include "../KeyCodes.hpp"

#include <sstream>



namespace Engine
{

	class KeyEvent : public Event
	{
        public:
            KeyCode GetKeyCode() const { return mKeyCode; };
            EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

        protected:

            KeyEvent(const KeyCode keycode) : mKeyCode(keycode) {}
            KeyCode mKeyCode;
	};



	class KeyPressedEvent : public KeyEvent
	{
        public:
            KeyPressedEvent(const KeyCode keycode, bool isRepeat = false) : KeyEvent(keycode), mIsRepeat(isRepeat) {}
            bool IsRepeat() const { return mIsRepeat; }

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "KeyPressedEvent: " << mKeyCode << " (repeat = " << mIsRepeat << ")";
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyPressed);

        private:
            bool mIsRepeat;
	};



	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << mKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};



	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << mKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}



#endif // KEYEVENT_H_INCLUDED
