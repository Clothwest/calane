#pragma once

#include "Calane.h"

namespace Calane
{
	class Application
	{
	public:
		Application();
		~Application();

		void init();
		void run();

		void onEvent(Event &e);

		bool onWindowClose(WindowCloseEvent &e);

	private:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;

		bool m_Running = true;
	};
}

