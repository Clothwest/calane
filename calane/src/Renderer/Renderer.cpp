#include "clpch.h"
#include "Renderer.h"

namespace Calane
{
	Renderer::Renderer()
		: m_UtilVertexArray(new VertexArray())
	{
	}

	Renderer::~Renderer()
	{
		delete m_UtilVertexArray;
	}

	void Renderer::attach(const Shader &shader)
	{
		m_Shader = &shader;
	}

	void Renderer::attach(const VertexArray &vertexBuffer)
	{
		m_VertexArray = &vertexBuffer;
	}

	void Renderer::drawArrays(DrawMode mode, int first, int count)
	{
		glUseProgram(m_Shader->getID());
		
		glBindVertexArray(m_VertexArray->getID());
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexArray->getVertexBufferID());

		glDrawArrays((uint32_t)mode, first, count);
	}

	void Renderer::drawIndexes(DrawMode mode, int count, Type type)
	{
		glUseProgram(m_Shader->getID());

		glBindVertexArray(m_VertexArray->getID());
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexArray->getVertexBufferID());
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_VertexArray->getIndexBufferID());

		glDrawElements((uint32_t)mode, count, (uint32_t)type, nullptr);
	}
}
