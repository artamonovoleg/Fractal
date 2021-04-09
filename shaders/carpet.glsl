#version 330 core

uniform vec2 u_resolution;

out vec4 fragColor;

int maxIterations = 100;

float Map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

vec3 DrawCarpet(vec2 coord)
{
    int x = int(coord.x);
    int y = int(coord.y);
    int i = 0;

	while ((x > 0 || y > 0) && i < maxIterations)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return vec3(0.0);
		x /= 3;
		y /= 3;
		i++;
	}

    return vec3(1.0);
}

void main()
{
	vec2 coord = gl_FragCoord.xy;

	vec3 c = DrawCarpet(coord);
    fragColor = vec4(c, 1.0f);
}