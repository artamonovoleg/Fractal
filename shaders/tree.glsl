#version 330 core

uniform vec2 u_resolution;

out vec4 fragColor;

float Map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

vec3 DrawLine(vec2 coord, vec2 p1, vec2 p2, float width, vec3 color)
{
    vec2 v1 = coord - p1;
    vec2 v2 = p2 - p1;
    float j1 = dot(v1, v2);
    
    vec2 v3 = coord - p2;
    vec2 v4 = p1 - p2;
    float j2 = dot(v3, v4);
    
    float len;
    if (j1 > 0.0 && j2 > 0.0)
    {
        vec2 nv2 = normalize(v2);
        len = length(v1 - dot(v1, nv2) * nv2);
    }
    else
    {
        len = min(length(v1),length(v3));
    }
    return color * step(len, width);
}

void main()
{
	vec2 coord = gl_FragCoord.xy / u_resolution - vec2(0.5);

    vec3 c = DrawLine(coord, vec2(-0.5), vec2(0.5), 0.001, vec3(0.3));
    fragColor = vec4(c, 1.0f);
}