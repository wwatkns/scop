/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:33:55 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 12:10:05 by wwatkins         ###   ########.fr       */
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
void	init_glfw_win(t_env *env)
{
	int width;
	int height;

	env->win.ptr = glfwCreateWindow(env->win.w, env->win.h, "scop", NULL, NULL);
	glfwMakeContextCurrent(env->win.ptr);
	glfwGetFramebufferSize(env->win.ptr, &width, &height);
	glViewport(0, 0, width, height);

	glfwSetInputMode(env->win.ptr, GLFW_STICKY_KEYS, 1);
}

void	init_cam(t_env *env)
{
	t_vec4	up;

	up = (t_vec4) {0, 1, 0, 1};
	env->cam.pos = (t_vec4) {0, 0, 3, 1};
	env->cam.target = (t_vec4) {0, 0, 0, 1};
	env->cam.dir = vec3_normalize(vec3_sub(env->cam.pos, env->cam.target));
	env->cam.right = vec3_normalize(vec3_cross(up, env->cam.dir));
	env->cam.up = vec3_cross(env->cam.dir, env->cam.right);
	env->cam.front = vec3_cross(env->cam.up, env->cam.right);
}

void	init(t_env *env)
{
	env->cam.fov = 90;
	env->win.w = WINDOW_W;
	env->win.h = WINDOW_H;
	env->win.ratio = env->win.w / (float)env->win.h;
	init_glfw_env();
	init_glfw_win(env);
	init_cam(env);
}
