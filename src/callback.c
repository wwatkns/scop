/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:51:00 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/05 19:42:19 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_reset(t_env *env)
{
	int	i;

	i = -1;
	while (++i < 512)
		env->key.code[i] = 0;
}

void	key_pressed(t_env *env)
{
	if (glfwGetKey(env->win.ptr, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(env->win.ptr, GL_TRUE);
	if (glfwGetKey(env->win.ptr, GLFW_KEY_KP_ADD) == GLFW_PRESS)
		set_projection_matrix(&env->sim.projection, env->cam.fov += 1, env->win.ratio, 0.001f, 100.0f);
	if (glfwGetKey(env->win.ptr, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
		set_projection_matrix(&env->sim.projection, env->cam.fov -= 1, env->win.ratio, 0.001f, 100.0f);
	if (glfwGetKey(env->win.ptr, GLFW_KEY_I) == GLFW_PRESS)
		rotate(&env->model.rotation, (t_vec3) { 2, 0, 0 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_K) == GLFW_PRESS)
		rotate(&env->model.rotation, (t_vec3) { -2, 0, 0 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_J) == GLFW_PRESS)
		rotate(&env->model.rotation, (t_vec3) { 0, -2, 0 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_L) == GLFW_PRESS)
		rotate(&env->model.rotation, (t_vec3) { 0, 2, 0 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_W) == GLFW_PRESS)
		translate(&env->model.translation, (t_vec3) { 0, 0,  0.02 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_S) == GLFW_PRESS)
		translate(&env->model.translation, (t_vec3) { 0, 0, -0.02 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_A) == GLFW_PRESS)
		translate(&env->model.translation, (t_vec3) {  0.02, 0, 0 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_D) == GLFW_PRESS)
		translate(&env->model.translation, (t_vec3) { -0.02, 0, 0 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		translate(&env->model.translation, (t_vec3) {  0, -0.02, 0 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		translate(&env->model.translation, (t_vec3) {  0,  0.02, 0 });
	// env->key.code[GLFW_KEY_KP_ADD] = 1;
	// env->key.code[GLFW_KEY_KP_SUBTRACT] = 1;
	// set_projection_matrix(&env.sim.projection, env.sim.fov, env.win.ratio, 0.001f, 100.0f);
}
