#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Calane
{
	class Context
	{
	public:
		Context() = default;
		Context(GLFWwindow *windowHandle);

		void init();
		void swapBuffers();

	private:
		GLFWwindow *m_WindowHandle;
	};
}

