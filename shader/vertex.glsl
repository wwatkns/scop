#version 400 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform mat4	mvp;
uniform int		cmod;

flat out vec4	fragment_color_f;
smooth out vec4	fragment_color_s;

void	main()
{
	gl_Position = mvp * vec4(position, 1.0f);

	if (cmod == 0)
		fragment_color_s = vec4(position.y * 0.4f + 0.4f, position.y * 0.4f + 0.1f, 0.2f, 1.0f);
	if (cmod == 1)
		fragment_color_s = vec4(position * 0.4f + 0.4f, 1.0f);
	fragment_color_f = fragment_color_s;
}
