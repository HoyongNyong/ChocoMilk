#include<iostream>
#include "OpenGL_Context.h"

namespace ChocoMilk {

	OpenGL_Context::OpenGL_Context(GLFWwindow* window)
		:target_window(window) {}

	void OpenGL_Context::Init()
	{
		glfwMakeContextCurrent(target_window);
		if (!gladLoadGL(glfwGetProcAddress)) {
			std::cout << "Faild to init OpenGL!" << std::endl;
		}
	}

	void OpenGL_Context::set_OpenGL_Context_Version(int major, int minor)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

}