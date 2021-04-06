#include <iostream>
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.hpp"

int main()
{
    try
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        int width = 1920, height = 1080;
        GLFWwindow* pWindow = glfwCreateWindow(width, height, "Fractol", nullptr, nullptr);

        if (!pWindow)
            throw std::runtime_error("Failed to create window");

        glfwMakeContextCurrent(pWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            throw std::runtime_error("Failed to initialize GLAD");

        // setup OpenGL state
        glViewport(0, 0, width, height);
        glClearColor(0.2, 0.3, 0.4, 1.0);

        Shader shader("../shaders/vert.glsl", "../shaders/frag.glsl");
        

        unsigned int vao, vbo;
        glGenVertexArrays(1, &vao);

        while (!glfwWindowShouldClose(pWindow))
        {
            glfwPollEvents();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            shader.Bind();

            glBindVertexArray(vao);
            glDrawArrays(GL_TRIANGLES, 0, 6);

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
