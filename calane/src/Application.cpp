#include "clpch.h"
#include "Application.h"

#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1)
#define BIND_RENDERER_FN(fn) std::bind(&fn, m_Renderer.get())

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
		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		uint32_t indices[] = {
			0, 1, 2
		};

		//uint32_t vao;
		//glGenVertexArrays(1, &vao);
		//glBindVertexArray(vao);

		//uint32_t vbo;
		//glGenBuffers(1, &vbo);
		//glBindBuffer(GL_ARRAY_BUFFER, vbo);
		//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		//glEnableVertexAttribArray(0);
		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

		//uint32_t ibo;
		//glGenBuffers(1, &ibo);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//Shader shader("res/shaders/basic.vs", "res/shaders/basic.fs");
		//shader.bind();

		VertexBuffer vbo;
		vbo.setData(sizeof(vertices), vertices, DrawUsage::StaticDraw);

		IndexBuffer ibo;
		ibo.setData(sizeof(indices), indices, DrawUsage::StaticDraw);

		VertexArray vao;
		vao.setLayout(0, 3, Type::Float, false, 3 * sizeof(float), 0);
		vao.attach(vbo);
		vao.attach(ibo);

		Shader shader("res/shaders/basic.vs", "res/shaders/basic.fs");

		m_Renderer->attach(vao);
		m_Renderer->attach(shader);

		while (m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT);

			//glDrawArrays(GL_TRIANGLES, 0, 3);
			//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			m_Renderer->drawArrays(DrawMode::Triangles, 0, 3);

			m_Window->onUpdate();
		}
	}

	void Application::onEvent(Event &e)
	{
		//CL_TRACE(e);
	}

	void Application::init()
	{
		m_Window = std::make_unique<Window>();
		m_Window->setEventCallback(BIND_EVENT_FN(onEvent));

		m_Renderer = std::make_unique<Renderer>();
		VertexBuffer::setGetUtilVertexArrayIDCallback(BIND_RENDERER_FN(Renderer::getUtilVertexArrayID));
		IndexBuffer::setGetUtilVertexArrayIDCallback(BIND_RENDERER_FN(Renderer::getUtilVertexArrayID));
	}
}
