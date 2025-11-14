#pragma once

#include "RendererInternal.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Calane
{
	class VertexArray
	{

	public:
		VertexArray();
		~VertexArray();

		inline uint32_t getID() const { return m_RendererID; }

		inline uint32_t getVertexBufferID() const { return m_VertexBuffer->getID(); }
		inline uint32_t getIndexBufferID() const { return m_IndexBuffer->getID(); }

		void attach(const VertexBuffer &vertexbuffer);
		void attach(const IndexBuffer &indexBuffer);

		void setLayout(const uint32_t index, int size, Type type, bool normalized, int stride, int offset);

	private:
		uint32_t m_RendererID;

		const VertexBuffer *m_VertexBuffer = nullptr;
		const IndexBuffer *m_IndexBuffer = nullptr;
	};
}
