/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:33:55 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 18:32:33 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_glfw_env(void)
{
	if (!glfwInit())
		ft_putstr("ERROR: glfw initialization failed.");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ft_atoi(&OPENGL_VERSION[0]));
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, ft_atoi(&OPENGL_VERSION[2]));
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

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

void	init_matrices(t_env *env)
{
	mat4_set(&env->sim.model, IDENTITY);
	mat4_set(&env->sim.view, IDENTITY);
	set_projection_matrix(env, env->cam.fov);
	mat4_set(&env->model.rotation, IDENTITY);
	mat4_set(&env->model.translation, IDENTITY);
	vec3_set(&env->model.inertia, 0);
	vec3_set(&env->model.center_axis, 0);
}

void	init_cam(t_env *env)
{
	t_vec3	up;

	up = vec3(0, 1, 0);
	env->cam.pos = vec3(0, 0, 3);
	env->cam.target = vec3(0, 0, 0);
	env->cam.dir = vec3_normalize(vec3_sub(env->cam.pos, env->cam.target));
	env->cam.right = vec3_normalize(vec3_cross(up, env->cam.dir));
	env->cam.up = vec3_cross(env->cam.dir, env->cam.right);
	env->cam.front = vec3_cross(env->cam.up, env->cam.right);
	vec3_set(&env->cam.inertia, 0);
	env->cam.velocity = 0.005;
}

void	init(t_env *env, int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < MAX_KEYS)
		env->key[i].cooldown = 0;
	if (argc == 2 && ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".obj") == 0)
		env->model.filename = argv[1];
	else
		display_help();
	env->cam.fov = CAMERA_FOV;
	env->win.w = WINDOW_W;
	env->win.h = WINDOW_H;
	env->win.ratio = env->win.w / (float)env->win.h;
	init_glfw_env();
	init_glfw_win(env);
	init_cam(env);
	init_matrices(env);
	env->mod.wireframe = GL_FILL;
	env->mod.shading = 0;
	env->mod.focus = 1;
	env->mod.color = 0;
	env->mod.greyscale = 0;
	env->mod.mapping = 0;
	env->mod.texture = 0;
	env->model.velocity = 0.33;
}
