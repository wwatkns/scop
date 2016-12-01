#version 400 core
in vec4			fragment_color;
out vec4		color;

uniform vec4	mod_color;

void	main()
{
	color = (fragment_color + mod_color) / 2.0f;
}
