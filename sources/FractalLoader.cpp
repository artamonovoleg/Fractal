#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "FractalLoader.hpp"

FractalLoader::FractalLoader()
{
    m_Library.Load("Mandelbrot", "../shaders/vert.glsl", "../shaders/mandelbrot.glsl");
    m_Library.Load("Julia", "../shaders/vert.glsl", "../shaders/julia.glsl");
    m_Library.Load("Tree", "../shaders/vert.glsl", "../shaders/tree.glsl");
    m_Library.Load("Carpet", "../shaders/vert.glsl", "../shaders/carpet.glsl");

    m_CurrentFractal = m_Library.Get("Mandelbrot");
}

void FractalLoader::BindFractal(const glm::vec2& resolution)
{
    m_CurrentFractal->Bind();
    m_CurrentFractal->SetVec2("u_resolution", resolution);
}

void FractalLoader::OnUpdate(GLFWwindow* pWindow)
{
    if (glfwGetKey(pWindow, GLFW_KEY_M))
        m_CurrentFractal = m_Library.Get("Mandelbrot");
    else
    if (glfwGetKey(pWindow, GLFW_KEY_J))
        m_CurrentFractal = m_Library.Get("Julia");
    else
    if (glfwGetKey(pWindow, GLFW_KEY_T))
        m_CurrentFractal = m_Library.Get("Tree");
    else
    if (glfwGetKey(pWindow, GLFW_KEY_C))
        m_CurrentFractal = m_Library.Get("Carpet");
}