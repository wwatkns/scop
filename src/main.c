/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/30 16:52:14 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(int argc, char **argv)
{
	t_env	e;

	glfw_init_env();
	glfw_init_win(&e, 1280, 720);

	glfwSetKeyCallback(e.win.ptr, key_callback);

	// Create three vertices to define a simple triangle.
	GLfloat vertices[] = {
	    -0.5f, -0.5f, 0.0f,
	     0.5f, -0.5f, 0.0f,
	     0.0f,  0.5f, 0.0f
	};

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint	vertexShader;
	GLuint	fragmentShader;

	vertexShader = create_shader("../shader/vertex.glsl", GL_VERTEX_SHADER);
	fragmentShader = create_shader("../shader/fragment.glsl", GL_FRAGMENT_SHADER);

	GLuint	shaderProgram;
	shaderProgram = create_shader_program(vertexShader, fragmentShader);

	while(!glfwWindowShouldClose(e.win.ptr))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(e.win.ptr);
	}
	glfwTerminate();
	// tmp
	argc = 0;
	argv[0] = NULL;
	return (0);
}
