/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 15:30:02 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLfloat cubeVertices[] = {
	/* Positions */        /* Colors */
	-0.25f,  0.25f, 0.0f,  0.0f, 1.0f, 0.0f, // 0
	 0.25f,  0.25f, 0.0f,  0.0f, 0.0f, 1.0f, // 1
	 0.25f, -0.25f, 0.0f,  1.0f, 0.0f, 0.0f, // 2
	-0.25f, -0.25f, 0.0f,  0.0f, 1.0f, 1.0f, // 3
	-0.25f,  0.25f, 0.5f,  0.0f, 1.0f, 0.0f, // 4
	 0.25f,  0.25f, 0.5f,  0.0f, 0.0f, 1.0f, // 5
	 0.25f, -0.25f, 0.5f,  1.0f, 0.0f, 0.0f, // 6
	-0.25f, -0.25f, 0.5f,  0.0f, 1.0f, 1.0f  // 7
};

GLuint	cubeIndices[] = {
	/*	A cube has 6 faces, with 2 triangles/face, so 12 triangles total. */
	0, 1, 2,  0, 3, 2,  0, 4, 5,  0, 1, 5,  0, 4, 7,  0, 3, 7,
	6, 2, 1,  6, 5, 1,  6, 5, 4,  6, 7, 4,  6, 2, 3,  6, 7, 3
};

// GLfloat vertices[] = { // Simple quad
// 	// Positions		// Colors
// 	0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,	// Top Right
// 	0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,	// Bottom Right
//    -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,	// Bottom Left
//    -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f	// Top Left
// };
// GLuint indices[] = {	// Note that we start from 0!
// 	0, 1, 3,	// First Triangle
// 	1, 2, 3		// Second Triangle
// };

int		main(void)
{
	t_env	env;

	init_glfw_env();
	init_glfw_win(&env, 960, 960);

	/*	Create the key callback */
	glfwSetKeyCallback(env.win.ptr, key_callback);
	/*	Build and compile our shader program */
	build_shader_program(&env, "../shader/vertex.glsl", "../shader/fragment.glsl");
	/*	Create the objects buffers for the differents objects
		(vertex_buffer, vertex_array, element_buffer) */
	env.data.size_vertices = sizeof(cubeVertices);
	env.data.size_indices = sizeof(cubeIndices);
	create_buffers(&env, cubeVertices, cubeIndices, GL_DYNAMIC_DRAW);
	/*	Prevents stange bugs */
	glBindVertexArray(0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	while(!glfwWindowShouldClose(env.win.ptr))
	{
		/*	Events handler */
		glfwPollEvents();

		/*	Clears the color buffer */
		glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/*	Uniform test for color changing of the fragment shader */
		GLfloat	timeValue = glfwGetTime();
		GLfloat B = (sin(timeValue) / 2) + 0.5;
		GLfloat G = (sin(timeValue - 1.5) / 2) + 0.5;
		GLfloat	R = (cos(timeValue) / 2) + 0.5;
		GLint	vertexColorLocation = glGetUniformLocation(env.shader.program, "ourColor");

		/*	Uniform test for position changing of the vertex shader */
		GLfloat X = sin(timeValue);
		GLfloat Y = sin(timeValue * 1.5);
		GLint	vertexLocation = glGetUniformLocation(env.shader.program, "ourMod");
		GLfloat T = sin(timeValue * 0.75) * 180;
		GLint	vertexAngleLocation = glGetUniformLocation(env.shader.program, "ourAngle");

		/*	Activate the shader program */
		glUseProgram(env.shader.program);
		/*	Updates the uniform variable in the fragment shader */
		glUniform4f(vertexColorLocation, R, G, B, 1.0f);
		glUniform3f(vertexLocation, X, Y, 0.0f);
		glUniform1f(vertexAngleLocation, T);
		/*	Draw our rectangle using the shader program */
		glBindVertexArray(env.buffer.VAO);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0); // 36 is num of indices
		glBindVertexArray(0);

		/*	Swap the screen buffers (to display on screen the computed image) */
		glfwSwapBuffers(env.win.ptr);
	}
	clean_glfw(&env);
	return (0);
}
