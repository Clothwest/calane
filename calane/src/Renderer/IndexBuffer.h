#pragma once

#include "RendererInternal.h"

namespace Calane
{
	class IndexBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();

		inline uint32_t getID() const { return m_RendererID; }
		inline static void setGetUtilVertexArrayIDCallback(const GetIDCallback &getUtilVertexArrayIDCallback) { s_GetUtilVertexArrayIDCallback = getUtilVertexArrayIDCallback; }

		void setData(const int64_t size, const void *data, DrawUsage usage);

	private:
		uint32_t m_RendererID;

		static GetIDCallback s_GetUtilVertexArrayIDCallback;
	};
}
