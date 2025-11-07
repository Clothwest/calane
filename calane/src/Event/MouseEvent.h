#pragma once

#include "Event.h"

namespace Calane
{
	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float xPos, float yPos) : m_XPos(xPos), m_YPos(yPos) {}

		inline float getXPos() const { return m_XPos; }
		inline float getYPos() const { return m_YPos; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMove: " << m_XPos << ", " << m_YPos;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMove);

	private:
		float m_XPos, m_YPos;
	};

	class MouseButtonEvent : public Event
	{
	public:
		inline int getMouseButton() const { return m_Button; }

	protected:
		MouseButtonEvent(int button) : m_Button(button) {}

		int m_Button;
	};

	class MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPress);
	};

	class MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonRelease: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonRelease);
	};

	class MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float getXOffset() const { return m_XOffset; }
		inline float getYOffset() const { return m_YOffset; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScroll: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScroll);

	private:
		float m_XOffset, m_YOffset;
	};
}
