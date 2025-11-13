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
		inline static void setGetUsingIDCallback(const GetIDCallback &getUsingIDCallback) { s_GetUsingIDCallback = getUsingIDCallback; }

		inline uint32_t getVertexBufferID() const { return m_VertexBuffer->getID(); }
		inline uint32_t getIndexBufferID() const { return m_IndexBuffer->getID(); }

		void attach(VertexBuffer &vertexbuffer);
		void attach(IndexBuffer &indexBuffer);

		void setLayout(const uint32_t index, int size, Type type, bool normalized, int stride, int offset);

	private:
		uint32_t m_RendererID;

		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

		static GetIDCallback s_GetUsingIDCallback;
	};
}
