#pragma once

#include "ShaderLibrary.hpp"

struct GLFWwindow;

class FractalLoader
{
    private:
        ShaderLibrary m_Library;
        Shader* m_CurrentFractal = nullptr;
    public:
        FractalLoader();

        void BindFractal(const glm::vec2& resolution);

        void OnUpdate(GLFWwindow* pWindow);
};