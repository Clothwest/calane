#pragma once

#include <glad/glad.h>

namespace Calane
{
	using GetIDCallback = std::function<uint32_t(void)>;

	enum class Buffer : uint32_t
	{
		None = 0,
		Vertex = GL_ARRAY_BUFFER,
		Index = GL_ELEMENT_ARRAY_BUFFER
	};

	enum class DrawUsage : uint32_t
	{
		None = 0,
		StaticDraw = GL_STATIC_DRAW
	};

	enum class DrawMode : uint32_t
	{
		None = 0,
		Triangles = GL_TRIANGLES
	};

	enum class Type : uint32_t
	{
		Node = 0,
		Float = GL_FLOAT,
		UnsignedInt = GL_UNSIGNED_INT
	};
}
