#include "Renderer.h"
#include "ChocoMilk/core/Component/Entity.h"

namespace ChocoMilk {
	ShaderHolder* Renderer::currentShader = nullptr;
	Renderer::Renderer(){}
	void Renderer::setTargetWindow(){}
	void Renderer::created(){}
	void Renderer::update(){}

	void Renderer::setShader(ShaderHolder& shader)
	{
		/*
		currentShader = shader.getID();
		glUseProgram(currentShader);
		*/
		currentShader = &shader;
		glUseProgram(currentShader->getID());
	}
	void Renderer::resetShader()
	{
		setShader(*defaultShader);
	}
}