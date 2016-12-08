#version 400 core

flat in vec4	fragment_color_f;
smooth in vec4	fragment_color_s;

uniform bool	smod;

out vec4		color;

void	main()
{
	float	mean;

	// mean = (fragment_color.x + fragment_color.y + fragment_color.z) / 3.0;
	// color = vec4(mean);
	if (smod)
		color = fragment_color_s;
	else
		color = fragment_color_f;
}
