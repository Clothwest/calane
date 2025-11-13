#include "clpch.h"
#include "VertexBuffer.h"

#include <glad/glad.h>

namespace Calane
{
	GetIDCallback VertexBuffer::s_GetUtilVertexArrayIDCallback = nullptr;

	VertexBuffer::VertexBuffer()
	{
		glGenBuffers(1, &m_RendererID);
	}

	VertexBuffer::~VertexBuffer()
	{
	}

	void VertexBuffer::setData(const int64_t size, const void *data, DrawUsage usage)
	{
		uint32_t utilVertexArrayID = s_GetUtilVertexArrayIDCallback();
		glBindVertexArray(utilVertexArrayID);

		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, (uint32_t)usage);
	}
}
