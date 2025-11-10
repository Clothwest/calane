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

	void Application::init()
	{
		m_Window = std::make_unique<Window>();
		m_Window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	}

	void Application::run()
	{
		m_LayerStack.pushLayer(new Layer());

		while (m_Running)
		{
			glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer *layer : m_LayerStack)
			{
				layer->onUpdate();
			}

			m_Window->onUpdate();
		}
	}

	void Application::onEvent(Event &e)
	{
		CL_TRACE(e);
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); it++)
		{
			if (e.isHandled())
				break;
			(*it)->onEvent(e);
		}
	}

	bool Application::onWindowClose(WindowCloseEvent &e)
	{
		m_Running = false;
		return true;
	}
}
