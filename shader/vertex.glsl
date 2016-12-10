#version 400 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

# define PI 3.14159265359

uniform mat4	mvp;
uniform int		cmod;
uniform bool	mmod;

flat out vec4	fragment_color_f;
smooth out vec4	fragment_color_s;
out	vec2		texture_coordinates;

vec2	cylinder_mapping()
{
	float	u;
	float	v;

	u = 0.5 + atan(position.z, position.x) / PI * 0.5;
	v = position.y / 10.0;
	return (vec2(u, v) * 15);
}

void	main()
{
	gl_Position = mvp * vec4(position, 1.0f);
	if (cmod == 0)
		fragment_color_s = vec4(position.y * 0.4f + 0.4f,
		position.z * 0.1 + position.y * 0.4f + 0.1f, 0.2f, 1.0f);
	if (cmod == 1)
		fragment_color_s = vec4(position * 0.4f + 0.4f, 1.0f);
	fragment_color_f = fragment_color_s;
	if (mmod)
		texture_coordinates = cylinder_mapping();
	else
		texture_coordinates = vec2(position.x * 2, position.y * 2);
}
