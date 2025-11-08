#pragma once

#include "Event.h"

namespace Calane
{
	class KeyEvent : public Event
	{
	public:
		inline int getKeyCode() const { return m_KeyCode; }

	protected:
		KeyEvent(int keyCode) : m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	class KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPress: " << m_KeyCode << "(" << m_RepeatCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPress);

	private:
		int m_RepeatCount;
	};

	class KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyRelease: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyRelease);
	};
}
