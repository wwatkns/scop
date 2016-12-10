#version 400 core

flat in vec4		fragment_color_f;
smooth in vec4		fragment_color_s;
in vec2				texture_coordinates;

uniform bool		smod;
uniform bool		tmod;
uniform bool		gmod;
uniform sampler2D	ltexture;

out vec4		color;

void	main()
{
	float	grey;

	if (smod)
		color = fragment_color_s;
	else
		color = fragment_color_f;
	if (tmod)
		color = texture(ltexture, texture_coordinates);
	if (gmod)
	{
		grey = (0.2125 * color.x + 0.7154 * color.y + 0.0721 * color.z) / 3.0f;
		color = vec4(grey, grey, grey, 1.0f);
	}
}
