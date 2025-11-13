#include "clpch.h"
#include "IndexBuffer.h"

#include <glad/glad.h>

namespace Calane
{
	GetIDCallback IndexBuffer::s_GetUtilVertexArrayIDCallback = nullptr;

	IndexBuffer::IndexBuffer()
	{
		glGenBuffers(1, &m_RendererID);
	}

	IndexBuffer::~IndexBuffer()
	{

	}

	void IndexBuffer::setData(const int64_t size, const void *data, DrawUsage usage)
	{
		uint32_t utilVertexArrayID = s_GetUtilVertexArrayIDCallback();
		glBindVertexArray(utilVertexArrayID);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, (uint32_t)usage);
	}
}
