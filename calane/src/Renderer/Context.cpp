#include "clpch.h"
#include "Context.h"

#include "Core.h"

namespace Calane
{
	Context::Context(GLFWwindow *windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CL_ASSERT(m_WindowHandle, "Window handle is null");
	}

	void Context::init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CL_ASSERT(success, "Failed to initialize GLAD");
		
		CL_INFO("OpenGL Info:");
		CL_INFO("  Vendor: {0}", (const char *)glGetString(GL_VENDOR));
		CL_INFO("  Renderer: {0}", (const char *)glGetString(GL_RENDERER));
		CL_INFO("  Version: {0}", (const char *)glGetString(GL_VERSION));

		CL_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 6), "OpenGL version 4.6 required at least");
	}

	void Context::swapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
