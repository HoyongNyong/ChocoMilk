#include"Sprite.h"
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"

namespace ChocoMilk {
	unsigned int Sprite::sprNum = 0;
	res<Quad> Sprite::_SPR_Quad_ = nullptr;
	void Sprite::Init() {
		_SPR_Quad_ = std::make_shared<Quad>();
	}

	void Sprite::draw(Sprite& spr, float x, float y)
	{
		draw_ext(spr, x, y, 1.0f, 1.0f, 0.0f);
	}
	void Sprite::draw_ext(Sprite& spr, float x, float y, float xscale, float yscale, float angle)
	{
		glm::mat4 model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(x, y, 0.0f));
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(xscale, yscale, 1.0f));

		Renderer::getCurrentShader()->setMat4("model", model);

		sprDraw(spr);
	}
	void Sprite::sprDraw(Sprite& spr)
	{
		_SPR_Quad_->bind();
		spr.getTex().bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		_SPR_Quad_->unbind();
	}
	void Sprite::Draw()
	{
		sprDraw(*this);
	}
	Sprite::Sprite(const std::string& imgPath) : img(imgPath) {
		sprNum += 1;
	}
}
