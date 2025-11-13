#pragma once

#include <GLFW/glfw3.h>

#include "Event/Event.h"
#include "Renderer/Context.h"

namespace Calane
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string &title = "Calane", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event &)>;

		Window(const WindowProps &props = WindowProps());
		~Window();

		inline unsigned int getWidth() const { return m_Data.Width; }
		inline unsigned int getHeight() const { return m_Data.Height; }

		void onUpdate();

		inline void setEventCallback(const EventCallbackFn &callback) { m_Data.EventCallback = callback; }
		void setVSync(bool enabled);
		inline bool isVSync() const { return m_Data.VSync; }

	private:
		void init(const WindowProps &props);
		void shutdown();

	private:
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		GLFWwindow *m_Window;
		WindowData m_Data;
		Context m_Context;
	};
}
