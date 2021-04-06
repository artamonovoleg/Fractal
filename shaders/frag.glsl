#version 330 core
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec2 uv;

out vec4 fragColor;

void main()
{
    float cx = uv.x;
    if (uv.x >= 0.5)
        cx = 1.0f;
    fragColor = vec4(cx, uv.y, 1.0f, 1.0f);
}
