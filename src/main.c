/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/30 17:52:13 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(int argc, char **argv)
{
	t_env	e;

	glfw_init_env();
	glfw_init_win(&e, 1280, 720);

	glfwSetKeyCallback(e.win.ptr, key_callback);

	e.shader.vertex = create_shader("../shader/vertex.glsl", GL_VERTEX_SHADER);
	e.shader.fragment = create_shader("../shader/fragment.glsl", GL_FRAGMENT_SHADER);
	e.shader.program = create_shader_program(e.shader.vertex, e.shader.fragment);
	// Create three vertices to define a simple triangle.
	GLfloat vertices[] = {
	    -0.5f, -0.5f, 0.0f,
	     0.5f, -0.5f, 0.0f,
	     0.0f,  0.5f, 0.0f
	};

	glGenBuffers(1, &e.VBO);
	glGenVertexArrays(1, &e.VAO);

	glBindVertexArray(e.VAO);

	glBindBuffer(GL_ARRAY_BUFFER, e.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	while(!glfwWindowShouldClose(e.win.ptr))
	{
		glfwPollEvents();
		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(e.shader.program);
		glBindVertexArray(e.VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		glfwSwapBuffers(e.win.ptr);
	}
	glfwTerminate();
	// tmp
	argc = 0;
	argv[0] = NULL;
	return (0);
}
