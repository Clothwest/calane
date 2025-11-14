#pragma once

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include <glad/glad.h>

namespace Calane
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		inline uint32_t getUtilVertexArrayID() const { return m_UtilVertexArray->getID(); }
		inline uint32_t getShaderID() const { return m_Shader->getID(); }
		inline uint32_t getVertexArrayID() const { return m_VertexArray->getID(); }

		void attach(const Shader &shader);
		void attach(const VertexArray &vertexBuffer);

		void drawArrays(DrawMode mode, int first, int count);
		void drawIndexes(DrawMode mode, int count, Type type);

	private:
		VertexArray *m_UtilVertexArray = nullptr;

		const Shader *m_Shader = nullptr;
		const VertexArray *m_VertexArray = nullptr;
	};
}
