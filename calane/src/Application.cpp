#include "clpch.h"
#include "Application.h"

#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1)

namespace Calane
{
	Application::Application()
	{
		init();
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		while (m_Running)
		{
			m_Window->onUpdate();
		}
	}

	void Application::onEvent(Event &e)
	{
		CL_TRACE(e);
	}

	void Application::init()
	{
		m_Window = std::make_unique<Window>();
		m_Window->setEventCallback(BIND_EVENT_FN(onEvent));
	}
}
