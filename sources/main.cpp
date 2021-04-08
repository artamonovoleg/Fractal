#include <iostream>
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderLibrary.hpp"

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

        int width = 600, height = 500;
        GLFWwindow* pWindow = glfwCreateWindow(width, height, "Fractol", nullptr, nullptr);

        if (!pWindow)
            throw std::runtime_error("Failed to create window");

        glfwMakeContextCurrent(pWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            throw std::runtime_error("Failed to initialize GLAD");

        // setup OpenGL state
        glClearColor(0.2, 0.3, 0.4, 1.0);
        glViewport(0, 0, width, height);

        // Shader shader("../shaders/vert.glsl", "../shaders/julia.glsl");

        ShaderLibrary lib;
        lib.Load("Mandelbrot", "../shaders/vert.glsl", "../shaders/mandelbrot.glsl");
        lib.Load("Julia", "../shaders/vert.glsl", "../shaders/julia.glsl");
        
        Shader* currentShader = lib.Get("Julia");

        unsigned int vao, vbo;
        glGenVertexArrays(1, &vao);

        while (!glfwWindowShouldClose(pWindow))
        {
            glfwPollEvents();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            currentShader->Bind();
            currentShader->SetVec2("u_resolution", GetResolution(pWindow));
            glBindVertexArray(vao);
            glDrawArrays(GL_TRIANGLES, 0, 6);

            if (glfwGetKey(pWindow, GLFW_KEY_M))
                currentShader = lib.Get("Mandelbrot");
            if (glfwGetKey(pWindow, GLFW_KEY_J))
                currentShader = lib.Get("Julia");

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
