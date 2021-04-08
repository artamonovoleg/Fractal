#version 330 core

uniform vec2 u_resolution;

out vec4 fragColor;

int maxIterations = 100;

float Map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

vec2 SquareImaginary(vec2 number)
{
	return vec2(
        pow(number.x, 2) - pow(number.y, 2),
		2 * number.x * number.y
	);
}

vec3 IterateJulia(vec2 coord)
{
	vec2 z = coord;
	for(int i = 0; i < maxIterations; i++)
	{
		z = SquareImaginary(z);
		z.x = z.x - 0.4;
		z.y = z.y - 0.6;

		if (length(z) > 2)
		{
			float color = 1.0 - float(i) / maxIterations;
			return vec3(color);
		}
	}

	return vec3(0.0);
}

void main()
{
	vec2 coord = gl_FragCoord.xy / u_resolution - vec2(1.0);
	coord = vec2(Map(coord.x, -1.0, 1.0, -1.5, 1.5), Map(coord.y, -1.0, 1.0, -1.5, 1.5));

	vec3 c = IterateJulia(coord);
    fragColor = vec4(c, 1.0f);
}