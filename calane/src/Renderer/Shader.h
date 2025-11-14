#pragma once

#include "RendererInternal.h"

namespace Calane
{
	class Shader
	{
	public:
		Shader(const std::string &vertexPath, const std::string &fragmentPath);
		~Shader();

		inline uint32_t getID() const { return m_RendererID; }

		template <int C, typename T, typename... Args>
		bool setUniform(const std::string &uniformName, Args&&... args);
		
		template <typename T, typename... Args>
		bool setUniform(const std::string &uniformName, Args&&... args);

	private:
		int getUniformLocation(const std::string &uniformName);

	private:
		uint32_t m_RendererID;
		std::unordered_map<std::string, int> m_LocationCache;
	};

	template <int C, typename T, typename... Args>
	bool Shader::setUniform(const std::string &uniformName, Args&&... args)
	{
		static_assert(sizeof...(Args) == C);
		static_assert((std::is_convertible_v<Args, T> && ...));

		int uniformLocation = getUniformLocation(uniformName);
		if (uniformLocation == -1)
			return false;

		uint32_t usingShaderID = s_GetUsingIDCallback();

		glUseProgram(m_RendererID);

		if constexpr (C == 1 && std::is_same_v<T, float>)
			glUniform1f(uniformLocation, static_cast<T>(args)...);
		else if constexpr (C == 2 && std::is_same_v<T, float>)
			glUniform2f(uniformLocation, static_cast<T>(args)...);
		else if constexpr (C == 3 && std::is_same_v<T, float>)
			glUniform3f(uniformLocation, static_cast<T>(args)...);
		else if constexpr (C == 4 && std::is_same_v<T, float>)
			glUniform4f(uniformLocation, static_cast<T>(args)...);

		else if constexpr (C == 1 && std::is_same_v<T, int>)
			glUniform1i(uniformLocation, static_cast<T>(args)...);
		else if constexpr (C == 2 && std::is_same_v<T, int>)
			glUniform2i(uniformLocation, static_cast<T>(args)...);
		else if constexpr (C == 3 && std::is_same_v<T, int>)
			glUniform3i(uniformLocation, static_cast<T>(args)...);
		else if constexpr (C == 4 && std::is_same_v<T, int>)
			glUniform4i(uniformLocation, static_cast<T>(args)...);

		else
			static_assert(false);

		glUseProgram(usingShaderID);

		return true;
	}

	template <typename T, typename... Args>
	bool Shader::setUniform(const std::string &uniformName, Args&&... args)
	{
		return setUniform<sizeof...(Args), T>(uniformName, std::forward<T>(args)...);
	}
}
