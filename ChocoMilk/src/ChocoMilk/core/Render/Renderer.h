#pragma once

#include "Shader.h"

namespace ChocoMilk {
	class Renderer {
	public:
		Renderer();
		void setTargetWindow();
		void created();
		void update();

		void setDefaultShader(ShaderHolder* shader) { defaultShader = shader; }

		void setShader(ShaderHolder& shader);
		void resetShader();

		static ShaderHolder* getCurrentShader() { return currentShader; }

	private:
		ShaderHolder* defaultShader = nullptr;
		static ShaderHolder* currentShader;
	};
}
