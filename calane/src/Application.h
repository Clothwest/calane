#pragma once

#include <GLFW/glfw3.h>

namespace Calane
{
	class Application
	{
	public:
		Application();
		~Application();

	private:
		void init();

	private:
		std::unique_ptr<GLFWwindow> window;
	};
}

