#pragma once

#include "Core.h"
#include "fmt/ostream.h"

namespace Calane
{
	enum class EventType
	{
		None = 0,
		WindowResize, WindowClose,
		KeyPress, KeyRelease,
		MouseMove, MouseButtonPress, MouseButtonRelease, MouseScroll
	};

	class Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType getEventType() const = 0;
		virtual const char *getName() const = 0;
		virtual std::string toString() const { return getName(); };

	private:
		bool m_Handled = false;
	};

#define EVENT_CLASS_TYPE(type) inline static EventType getStaticType() { return EventType::##type; }\
								inline virtual EventType getEventType() const override { return getStaticType(); }\
								inline virtual const char *getName() const override { return #type; }

	class EventDispatcher
	{
		template <typename T>
		using EventFn = std::function<bool(T &)>;
	public:
		EventDispatcher(Event &event) : m_Event(event) {}

		template <typename T>
		bool dispatch(EventFn<T> func)
		{
			if (m_Event.getEventType() == T::getStaticType())
			{
				m_Event.m_Handled = func(*(T *)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event &m_Event;
	};
}


template <typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_base_of_v<Calane::Event, T>, char>> : public fmt::formatter<std::string>
{
	format_context::iterator format(const T &e, format_context &ctx) const
	{
		return formatter<std::string>::format(e.toString(), ctx);
	}
};
