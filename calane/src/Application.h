#pragma once

#include "Calane.h"

namespace Calane
{
	class Application
	{
	public:
		Application();
		~Application();

		void run();

		void onEvent(Event &e);

	private:
		void init();

	private:
		bool m_Running = true;

		std::unique_ptr<Window> m_Window;
		std::unique_ptr<Renderer> m_Renderer;
	};
}

