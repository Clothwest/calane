#include "clpch.h"
#include "Renderer.h"

namespace Calane
{
	Renderer::Renderer()
		: m_UtilVertexArray(std::make_unique<VertexArray>())
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::attach(Shader &shader)
	{
		m_Shader.reset(&shader);
	}

	void Renderer::attach(VertexArray &vertexBuffer)
	{
		m_VertexArray.reset(&vertexBuffer);
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
