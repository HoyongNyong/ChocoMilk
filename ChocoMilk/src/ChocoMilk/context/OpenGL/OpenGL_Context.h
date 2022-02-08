#pragma once
#include "glad/gl.h"
#include "GLFW/glfw3.h"

namespace ChocoMilk {

	class OpenGL_Context {
	public:
		OpenGL_Context(GLFWwindow* window);
		void Init();
		void set_OpenGL_Context_Version(int major, int minor);
	
	private:
		GLFWwindow* target_window;
	};

}
