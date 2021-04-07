#version 330 core
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec2 uv;

uniform vec2 u_resolution;

out vec4 fragColor;

int maxIterations = 50;


float map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

vec2 squareImaginary(vec2 number)
{
	return vec2(
		pow(number.x, 2) - pow(number.y, 2),
		2 * number.x * number.y
	);
}

vec3 IterateMandelbrot(vec2 coord)
{
	vec2 z = vec2(0, 0);

	for(int i = 0; i < maxIterations; i++)
	{
		z = squareImaginary(z) + coord;
		if (length(z) > 2) 
		{
			if (i == 0)
				return vec3(0.2, 0.3, 0.4);
			else
			if (i == 1)
				return vec3(0.2, 0.3, 0.5);
			else
			if (i == 2)
				return vec3(0.2, 0.3, 0.6);
			else
			if (i == 3)
				return vec3(0.2, 0.3, 0.7);
			else
			if (i == 4)
				return vec3(0.2, 0.3, 0.8);
			else
			if (i == 5)
				return vec3(0.2, 0.3, 0.9);
			else
			if (i == 6)
				return vec3(0.2, 0.4, 0.9);
			else
			if (i == 7)
				return vec3(0.2, 0.5, 0.9);
			else
			if (i == 8)
				return vec3(0.2, 0.6, 0.9);
			else
			if (i == 9)
				return vec3(0.2, 0.7, 0.9);
			else
			if (i == 10)
				return vec3(0.2, 0.8, 0.9);
			else
			if (i == 11)
				return vec3(0.2, 0.9, 0.9);
			else
			if (i == 12)
				return vec3(0.3, 0.9, 0.9);
			else
			if (i == 13)
				return vec3(0.4, 0.9, 0.9);
			else
				return vec3(0.9412, 0.8627, 0.1529);
		}
	}

	return vec3(0.9412, 0.102, 0.102);
}

void main()
{
	vec2 coord = gl_FragCoord.xy / u_resolution - vec2(1.0);
	coord = vec2(map(coord.x, -1.0, 1.0, -2.0, 1.0), coord.y);

	vec3 c = IterateMandelbrot(coord);
    fragColor = vec4(c, 1.0f);
}
