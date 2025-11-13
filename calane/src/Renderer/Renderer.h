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

		void attach(Shader &shader);
		void attach(VertexArray &vertexBuffer);

		void drawArrays(DrawMode mode, int first, int count);
		void drawIndexes(DrawMode mode, int count, Type type);

	private:
		std::unique_ptr<VertexArray> m_UtilVertexArray;

		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexArray> m_VertexArray;
	};
}
