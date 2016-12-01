#version 400 core

in vec4	baseColor;

out vec4 color;

uniform vec4	ourColor;

void	main()
{
	color = (baseColor + ourColor) / 2.0f;
}
