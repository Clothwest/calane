#include "clpch.h"
#include "Shader.h"

#include "Core.h"

namespace Calane
{
	static uint32_t createShader(uint32_t type, const std::string &path)
	{
		std::ifstream shaderFile;
		shaderFile.open(path);
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		std::string shaderSource = shaderStream.str();
		const char *source = shaderSource.c_str();

		uint32_t shader = glCreateShader(type);
		glShaderSource(shader, 1, &source, nullptr);
		glCompileShader(shader);

		int success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char infoLog[512];
			glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
			const char *shaderName;
			if (type == GL_VERTEX_SHADER)
				shaderName = "Vertex";
			else if (type == GL_FRAGMENT_SHADER)
				shaderName = "Fragment";
			else
				shaderName = "Other";
			CL_ERROR("{0}: {1}", shaderName, infoLog);
			CL_ASSERT(false, "Failed to compile shader");
		}

		return shader;
	}

	static uint32_t createShaderProgram(uint32_t vertexShader, uint32_t fragmentShader)
	{
		uint32_t program = glCreateProgram();
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glLinkProgram(program);

		int success;
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			char infoLog[512];
			glGetProgramInfoLog(program, sizeof(infoLog), nullptr, infoLog);
			CL_ERROR("{0}: {1}", "Program linking", infoLog);
			CL_ASSERT(false, "Failed to link program");
		}

		return program;
	}

	Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath)
	{
		uint32_t vertexShader = createShader(GL_VERTEX_SHADER, vertexPath);
		uint32_t fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentPath);

		m_RendererID = createShaderProgram(vertexShader, fragmentShader);
	}

	Shader::~Shader()
	{
	}

	int Shader::getUniformLocation(const std::string &uniformName)
	{
		if (m_LocationCache.find(uniformName) == m_LocationCache.end())
		{
			int location = m_LocationCache[uniformName] = glGetUniformLocation(m_RendererID, uniformName.c_str());
			if (location == -1)
				CL_WARN("Couldn't find {}", uniformName);
		}

		return m_LocationCache[uniformName];
	}
}
