#pragma once
#include "glad/gl.h"
#include"GLFW/glfw3.h"
#include"../cmpch.h"
#include"ChocoMilk/context/OpenGL/OpenGL_Context.h"

namespace ChocoMilk {
	class WindowHandler {
	public:
        WindowHandler(const std::string Title, int w, int h);
        ~WindowHandler();

        void ShutDown();
        void update();

        int getWidth() { return width; }
        int getHeight() { return height; }

        GLFWwindow* getNativeWindow() const;
    private:
        void Init(const std::string& title, int w, int h);
	private:
		GLFWwindow* window = nullptr;
        OpenGL_Context* context = nullptr;

        std::string title;
        int width = 1600;
        int height = 900;
    };
}
