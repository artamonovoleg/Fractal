#version 330 core

uniform vec2 u_resolution;

out vec4 fragColor;

int maxIterations = 1000;

float Map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

vec3 DrawCarpet(vec2 coord)
{
    ivec2 ip = ivec2(coord);
    float size = u_resolution.y;
    // int i = 0;

	// while ((p.x > 0 || p.y > 0) && i < maxIterations)
	// {
	// 	if (p.x % 3 == 1 && p.y % 3 == 1)
	// 		return vec3(1.0);
	// 	p.x /= 3;
	// 	p.y /= 3;
	// 	i++;
	// }

    while(size > 1.0) 
    {
        size /= 3.0;
        ip = ivec2(round(coord / size));

        if(ip.x == 0 && ip.y == 0) {
            return vec3(min(size*size, 1.0));
        } else {
            coord -= vec2(ip) * size;
        }
    }

    return vec3(0.0);
}

void main()
{
    vec2 coord = gl_FragCoord.xy - u_resolution / 2.0;
    float rot = 0.0;
	coord = mat2(cos(-rot), sin(-rot), -sin(-rot), cos(-rot)) * vec2(coord);

	vec3 c = DrawCarpet(coord);
    fragColor = vec4(c, 1.0f);
}