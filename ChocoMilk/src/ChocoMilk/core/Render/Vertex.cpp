#include"Vertex.h"

namespace ChocoMilk {
	VBO::VBO(){}
	VBO::VBO(const float* vertices, unsigned int size) : mSize(size), mVertices(vertices) {
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, mSize * sizeof(float), mVertices, GL_STATIC_DRAW);
	}

	void VBO::gen(const float* vertices, unsigned int size){
		mSize = size;
		mVertices = vertices;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, mSize * sizeof(float), mVertices, GL_STATIC_DRAW);
	}

	void VBO::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
	}
	void VBO::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void VBO::destroy()
	{
		glDeleteBuffers(1, &vbo);
	}

	void VBO::setAttrib(int layout, int size, int start, int stride)
	{
		bind();
		glVertexAttribPointer(layout, size, GL_FLOAT, GL_FALSE, stride, (void*)(start*sizeof(float)));
		glEnableVertexAttribArray(layout);
		unbind();
	}

	IBO::IBO(){}
	IBO::IBO(const unsigned int* indicies, unsigned int num) : mNum(num), mIndicies(indicies) {
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * mNum * sizeof(unsigned int), mIndicies, GL_STATIC_DRAW);
	}
	void IBO::gen(const unsigned int* indicies, unsigned int num) {
		mNum = num; mIndicies = indicies;

		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * mNum * sizeof(unsigned int), mIndicies, GL_STATIC_DRAW);
	}
	void IBO::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	}
	void IBO::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	void IBO::destroy()
	{
		glDeleteBuffers(1, &ibo);
	}
	VAO::VAO()
	{
		glGenVertexArrays(1, &vao);
	}
	VAO::~VAO()
	{
		destroy();
	}
	void VAO::bind()
	{
		glBindVertexArray(vao);
	}
	void VAO::unbind()
	{
		glBindVertexArray(0);
	}
	void VAO::destroy()
	{
		glDeleteVertexArrays(1, &vao);
	}
}
