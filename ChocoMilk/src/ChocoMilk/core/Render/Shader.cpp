#include "Shader.h"

namespace ChocoMilk {

	ShaderResource::ShaderResource(ShaderType srctype, const std::string& srcpath)
		:path(srcpath), type(srctype)
	{
		compile();
	}
	unsigned int ShaderResource::getID()
	{
		return shader;
	}
	void ShaderResource::compile()
	{
		GLenum TYPE;
		switch (type) {
		case ShaderType::vertex:
			TYPE = GL_VERTEX_SHADER; break;
		case ShaderType::fragment:
			TYPE = GL_FRAGMENT_SHADER; break;
		}

		shader = glCreateShader(TYPE);
		std::string src = ChocoMilk::LoadShader(path).c_str();
		const char* src_c = src.c_str();
		glShaderSource(shader, 1, &src_c, nullptr);
		glCompileShader(shader);
	}

	ShaderHolder::ShaderHolder()
	{
		shaders.reserve(2);
		shaderProgram = glCreateProgram();
	}
	ShaderHolder::ShaderHolder(unsigned int vertexShd, unsigned int fragmentShd)
	{
		shaders.reserve(2);
		shaderProgram = glCreateProgram();
		add(vertexShd);
		add(fragmentShd);
	}

	void ShaderHolder::add(unsigned int shader)
	{
		shaders.push_back(shader);
	}
	void ShaderHolder::link() {
		for (unsigned int shader : shaders) {
			glAttachShader(shaderProgram, shader);
		}

		glLinkProgram(shaderProgram);

		for (unsigned int shader : shaders) {
			glDeleteShader(shader);
		}
	}
	void ShaderHolder::destroy() {
		/*
		for (unsigned int shader : shaders) {
			glDetachShader(shaderProgram, shader);
		}*/
		glDeleteProgram(shaderProgram);
	}
	void ShaderHolder::setInt(const std::string& uniform, const int num)
	{
		unsigned int uniformId = glGetUniformLocation(shaderProgram, uniform.c_str());
		glUniform1i(uniformId, num);
	}
	void ShaderHolder::setFloat(const std::string& uniform, const float num)
	{
		unsigned int uniformId = glGetUniformLocation(shaderProgram, uniform.c_str());
		glUniform1f(uniformId, num);
	}
	void ShaderHolder::setMat4(const std::string& uniform, const glm::mat4 mat)
	{
		unsigned int uniformId = glGetUniformLocation(shaderProgram, uniform.c_str());
		glUniformMatrix4fv(uniformId, 1, GL_FALSE, glm::value_ptr(mat));
	}
}