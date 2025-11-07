#include "clpch.h"
#include "Window.h"

#include "Event/WindowEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"

namespace Calane
{
	static bool s_glfwInitialized = false;

	static void glfw_errorCallback(int error_code, const char *description)
	{
		CL_ERROR("GLFW Error: {0}, {1}", error_code, description);
	}

	Window::Window(const WindowProps &props)
	{
		init(props);
	}

	Window::~Window()
	{
		shutdown();
	}

	void Window::onUpdate()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Window::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	void Window::init(const WindowProps &props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		CL_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_glfwInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			CL_ASSERT(success, "Could not initialize GLFW");
			glfwSetErrorCallback(glfw_errorCallback);

			s_glfwInitialized = true;
		}

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(false);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
			});
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data.EventCallback(event);
			});
		
		glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleaseEvent event(key);
					data.EventCallback(event);
					break;
				}
			}
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xpos, double ypos) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			MouseMoveEvent event(xpos, ypos);
			data.EventCallback(event);
			});
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressEvent event(button);
					data.EventCallback(event);
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleaseEvent event(button);
					data.EventCallback(event);
				}
			}
			});
		glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xoffset, double yoffset) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			MouseScrollEvent event(xoffset, yoffset);
			data.EventCallback(event);
			});
	}

	void Window::shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}
