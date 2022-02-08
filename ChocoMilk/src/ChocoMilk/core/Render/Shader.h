#pragma once

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>

#include"glad/gl.h"
#include"glm/gtc/type_ptr.hpp"
#include<vector>

namespace ChocoMilk {
	static std::string LoadShader(const std::string& path) {
		std::ifstream stream(path);
		std::string line;
		std::stringstream shader;

		bool isShader = false;
		while ( getline(stream, line) ) {
			if (line.find("#shader") != std::string::npos) {
				isShader = true;
			}
			else {
				if (isShader) {
					shader << line << '\n';
				}
			}
		}
		return shader.str();
	}

	enum class ShaderType {
		vertex = 0,
		fragment
	};

	class ShaderResource { //좀 갈아 엎어야할 듯
	public:
		ShaderResource(ShaderType srctype, const std::string& srcpath);
		unsigned int getID();
		void compile();
	private:
		unsigned int shader;
		std::string path;
		ShaderType type;
	};

	class ShaderHolder {
	public:
		ShaderHolder();
		ShaderHolder(unsigned int vertexShd, unsigned int fragmentShd);
		void add(unsigned int shader);

		void link();
		void destroy();

		void setInt(const std::string& uniform, const int num);
		void setFloat(const std::string& uniform, const float num);
		void setMat4(const std::string& uniform, const glm::mat4 mat);

		inline unsigned int getID() { return shaderProgram; }

	private:
		unsigned int shaderProgram;
		std::vector<unsigned int> shaders;
	};
}
