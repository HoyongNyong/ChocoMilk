#pragma once

#include "ChocoMilk/cmpch.h"
#include "ChocoMilk/core/Render/Vertex.h"

namespace ChocoMilk {

	const float quad_V[] = {
		-0.5f, -0.5f,    0.0f, 0.0f,
		 0.5f, -0.5f,    1.0f, 0.0f,
		 0.5f,  0.5f,    1.0f, 1.0f,
		-0.5f,  0.5f,    0.0f, 1.0f
	};
	const unsigned int quad_I[] = {
		0, 1, 2,
		2, 3, 0
	};

	class Quad {
	public:
		Quad() {
			vao.bind();

			vbo.gen(quad_V, 8 * 2);
			vbo.setAttrib(0, 2, 0, sizeof(float) * 4);
			vbo.setAttrib(1, 2, 2, sizeof(float) * 4);
			ibo.gen(quad_I, 2);

			vao.unbind();
			vbo.unbind();
			ibo.unbind();
		}
		~Quad() {
			vao.destroy();
			vbo.destroy();
			ibo.destroy();
		}

		void bind() {
			vao.bind();
		}
		void unbind() {
			vao.unbind();
		}
	private:
		VAO vao;
		VBO vbo;
		IBO ibo;
	};

}
