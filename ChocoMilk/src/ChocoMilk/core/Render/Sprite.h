#pragma once

#include"ChocoMilk/cmpch.h"
#include"Texture.h"
#include"Vertex.h"
#include"ChocoMilk/core/Unit/Quad.h"

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"
#include"Renderer.h"

#include<string>

namespace ChocoMilk {
	class Sprite {
	public:
		Sprite(const std::string& imgPath);
		Texture& getTex() { return img; }

		static unsigned int sprNum;

		static void Init();
		static void draw(Sprite& spr, float x, float y);
		static void draw_ext(Sprite& spr, float x, float y, float xscale, float yscale, float angle);
		static void sprDraw(Sprite& spr);

		void Draw();
	private:
		static res<Quad> _SPR_Quad_;
		Texture img;
	};
}


