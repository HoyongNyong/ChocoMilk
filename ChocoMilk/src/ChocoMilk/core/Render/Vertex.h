#pragma once

#include"glad/gl.h"

namespace ChocoMilk {

	class VAO {
	public :
		VAO();
		~VAO();
		void bind();
		void unbind();
		void destroy();
	private:
		unsigned int vao;
	};

	class VBO {
	public:
		VBO();
		VBO(const float* vertices, unsigned int size);
		
		void gen(const float* vertices, unsigned int size);
		void bind();
		void unbind();
		void destroy();

		void setAttrib(int layout, int size, int start, int stride);

	private:
		unsigned int vbo;
		unsigned int mSize;
		const float* mVertices;
	};

	class IBO {
	public:
		IBO();
		IBO(const unsigned int* indicies, unsigned int size);

		void gen(const unsigned int* indicies, unsigned int num);
		void bind();
		void unbind();
		void destroy();

	private:
		unsigned int ibo;
		unsigned int mNum;
		const unsigned int* mIndicies;
	};

}

