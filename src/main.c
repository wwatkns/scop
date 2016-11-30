/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/30 14:33:38 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(int argc, char **argv)
{
	t_env	e;

	glfw_init_env();
	glfw_init_win(&e, 1280, 720);

	glfwSetKeyCallback(e.win.ptr, key_callback);

	GLfloat vertices[] = {
	    -0.5f, -0.5f, 0.0f,
	     0.5f, -0.5f, 0.0f,
	     0.0f,  0.5f, 0.0f
	};

	// Creates a VBO (vertex buffer object), it will be on GPU memory.
	GLuint VBO;
	glGenBuffers(1, &VBO);
	// Binds a VBO to a type of buffer.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Copy user-defined data to the specified buffer type (here, GL_ARRAY_BUFFER).
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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
