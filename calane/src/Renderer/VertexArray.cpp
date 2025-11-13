#include "clpch.h"
#include "VertexArray.h"

#include <glad/glad.h>

namespace Calane
{
	GetIDCallback VertexArray::s_GetUsingIDCallback = nullptr;

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_RendererID);
	}

	VertexArray::~VertexArray()
	{
	}

	void VertexArray::attach(VertexBuffer &vertexbuffer)
	{
		m_VertexBuffer.reset(&vertexbuffer);
	}

	void VertexArray::attach(IndexBuffer &indexBuffer)
	{
		m_IndexBuffer.reset(&indexBuffer);
	}

	void VertexArray::setLayout(const uint32_t index, int size, Type type, bool normalized, int stride, int offset)
	{
		glBindVertexArray(m_RendererID);
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, (uint32_t)type, normalized, stride, (const void *)offset);
	}
}
