#include "clpch.h"
#include "Application.h"

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
		m_Window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	}
}
