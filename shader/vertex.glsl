#version 400 core
layout (location = 0) in vec3 position;

uniform mat4	mvp;
out vec4		fragment_color;

void	main()
{
	gl_Position = mvp * vec4(position, 1.0f);
	fragment_color = vec4(position * 0.5f + 0.2f, 1.0f);
	// fragment_color = vec4(0.2f, 0.7f, 0.6f, 1.0f);
}
