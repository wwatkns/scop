/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:33:55 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 11:38:44 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*	Initialize the OpenGL environment.
*/
void	init_glfw_env(void)
{
	if (!glfwInit())
		printf("ERROR: glfw initialization failed.");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ft_atoi(&OPENGL_VERSION[0]));
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, ft_atoi(&OPENGL_VERSION[2]));
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

/* Initialize the OpenGL window.
*/
void	init_glfw_win(t_env *env, int w, int h)
{
	int width;
	int height;

	env->win.ptr = glfwCreateWindow(w, h, "test_OpenGL", NULL, NULL);
	glfwMakeContextCurrent(env->win.ptr);
	glfwGetFramebufferSize(env->win.ptr, &width, &height);
	glViewport(0, 0, width, height);
}
