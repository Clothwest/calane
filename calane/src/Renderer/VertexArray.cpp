#include "clpch.h"
#include "VertexArray.h"

#include <glad/glad.h>

namespace Calane
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_RendererID);
	}

	VertexArray::~VertexArray()
	{
	}

	void VertexArray::attach(const VertexBuffer &vertexbuffer)
	{
		m_VertexBuffer = &vertexbuffer;
	}

	void VertexArray::attach(const IndexBuffer &indexBuffer)
	{
		m_IndexBuffer = &indexBuffer;
	}

	void VertexArray::setLayout(const uint32_t index, int size, Type type, bool normalized, int stride, int offset)
	{
		glBindVertexArray(m_RendererID);
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, (uint32_t)type, normalized, stride, (const void *)offset);
	}
}
