#include"WindowHandler.h"
#include"../context/OpenGL/OpenGL_Context.h"

namespace ChocoMilk {

    WindowHandler::WindowHandler(const std::string Title, int w, int h)
        :width(w), height(h), title(Title)
    {
        Init(Title, w, h);
    }

    WindowHandler::~WindowHandler()
    {
        ShutDown();
    }

    void WindowHandler::Init(const std::string& title, int w, int h)
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
        context = new OpenGL_Context(window);
        context->Init();
        //context->set_OpenGL_Context_Version(4, 6);
    }

    void WindowHandler::update()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void WindowHandler::ShutDown()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    GLFWwindow* WindowHandler::getNativeWindow() const
    {
        return window;
    }

}