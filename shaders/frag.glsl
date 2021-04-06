#version 330 core
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec2 uv;

out vec4 fragColor;

void main()
{
    fragColor = vec4(uv, 1.0f, 1.0f);
}
