#include <iostream>
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderLibrary.hpp"
#include "FractalLoader.hpp"

glm::vec2 GetResolution(GLFWwindow* pWindow)
{
    int width, height;
    glfwGetWindowSize(pWindow, &width, &height);
    return glm::vec2(width, height);
}

int main()
{
    try
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);
            glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);
        #endif

        int width = 600, height = 500;
        GLFWwindow* pWindow = glfwCreateWindow(width, height, "Fractol", nullptr, nullptr);

        if (!pWindow)
            throw std::runtime_error("Failed to create window");

        glfwMakeContextCurrent(pWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            throw std::runtime_error("Failed to initialize GLAD");

        // setup OpenGL state
        glClearColor(0.2, 0.3, 0.4, 1.0);

        FractalLoader loader;

        unsigned int vao, vbo;
        glGenVertexArrays(1, &vao);

        while (!glfwWindowShouldClose(pWindow))
        {
            glfwPollEvents();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glViewport(0, 0, width, height);

            loader.BindFractal(GetResolution(pWindow));
            glBindVertexArray(vao);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            loader.OnUpdate(pWindow);

            glfwSwapBuffers(pWindow);
        }
        
        glfwTerminate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
