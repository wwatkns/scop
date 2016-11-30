/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/30 18:30:40 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(int argc, char **argv)
{
	t_env	e;

	glfw_init_env();
	glfw_init_win(&e, 720, 720);

	glfwSetKeyCallback(e.win.ptr, key_callback);

	/*	Build and compile our shader program */
	e.shader.vertex = create_shader("../shader/vertex.glsl", GL_VERTEX_SHADER);
	e.shader.fragment = create_shader("../shader/fragment.glsl", GL_FRAGMENT_SHADER);
	e.shader.program = create_shader_program(e.shader.vertex, e.shader.fragment);

	GLfloat vertices[] = {
		0.5f,  0.5f, 0.0f,	// Top Right
		0.5f, -0.5f, 0.0f,	// Bottom Right
		-0.5f, -0.5f, 0.0f,	// Bottom Left
		-0.5f,  0.5f, 0.0f	// Top Left
	};
	GLuint indices[] = {	// Note that we start from 0!
		0, 1, 3,	// First Triangle
		1, 2, 3		// Second Triangle
	};

	/*	Create the object buffers for the differents objects
		(vertex_buffer, vertex_array, element_buffer) */
	glGenBuffers(1, &e.object.VBO);
	glGenBuffers(1, &e.object.EBO);
	glGenVertexArrays(1, &e.object.VAO);

	/*	Binds the objects to the correcsponding buffers with
		the vertex_array_object first */
	glBindVertexArray(e.object.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, e.object.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, e.object.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	/*	Prevents stange bugs */
	glBindVertexArray(0);

	while(!glfwWindowShouldClose(e.win.ptr))
	{
		/*	Events handler */
		glfwPollEvents();

		/*	Clears the color buffer */
		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/*	Draw our rectangle using the shader program */
		glUseProgram(e.shader.program);
		glBindVertexArray(e.object.VAO);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		/*	Swap the screen buffers (to display on screen the computed image) */
		glfwSwapBuffers(e.win.ptr);
	}
	/*	Properly clean all resources */
	glDeleteVertexArrays(1, &e.object.VAO);
	glDeleteBuffers(1, &e.object.VBO);
	glDeleteBuffers(1, &e.object.EBO);
	/*	Terminate GLFW and clean any resources allocated by GLFW */
	glfwTerminate();

	/*	Suppress warning */
	argc = 0;
	argv[0] = NULL;
	return (0);
}
