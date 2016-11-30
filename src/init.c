/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:33:55 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/30 13:49:56 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// Initialize the openGL environment.
void	glfw_init_env(void)
{
	if (!glfwInit())
		printf("ERROR: glfw initialization failed.");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ft_atoi(&OPENGL_VERSION[0]));
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, ft_atoi(&OPENGL_VERSION[2]));
	// Using OpenGL version 4.0
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	// Required on MacOSX
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

// Initialize the openGL window.
void	glfw_init_win(t_env *e, int w, int h)
{
	int width;
	int height;

	e->win.ptr = glfwCreateWindow(w, h, "test_OpenGL", NULL, NULL);
	glfwMakeContextCurrent(e->win.ptr);
	glfwGetFramebufferSize(e->win.ptr, &width, &height);
	glViewport(0, 0, width, height);
}
