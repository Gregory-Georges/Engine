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

        protected:

            KeyEvent(const KeyCode keycode) : mKeyCode(keycode) {}
            KeyCode mKeyCode;
	};



	class KeyPressedEvent : public KeyEvent
	{
        public:
            KeyPressedEvent(const KeyCode keycode, bool isRepeat = false) : KeyEvent(keycode), mIsRepeat(isRepeat) {}
            bool IsRepeat() const { return mIsRepeat; }

            EVENT_TYPE(KeyPressed);

        private:
            bool mIsRepeat;
	};



	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}

		EVENT_TYPE(KeyReleased);
	};



	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}

		EVENT_TYPE(KeyTyped);
	};
}



#endif // KEYEVENT_H_INCLUDED
