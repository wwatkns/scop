#version 400 core
layout (location = 0) in vec3 position;
// layout (location = 1) in vec3 color;

uniform mat4	mvp;

out vec4		fragment_color;

void	main()
{
	gl_Position = mvp * vec4(position, 1.0f);
	// fragment_color = vec4(color, 1.0f);
	fragment_color = vec4(0.0f, 0.5f, 1.0f, 1.0f);
}
