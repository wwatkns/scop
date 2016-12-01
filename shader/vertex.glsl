#version 400 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec4	baseColor;

uniform vec3	ourMod;

void	main()
{
	gl_Position = vec4((position + ourMod * 0.5), 1.0);
	baseColor = vec4(color, 1.0);
}
