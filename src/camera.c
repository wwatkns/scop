/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:13:45 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 13:17:13 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	camera_zoom(t_env *env)
{
	if (env->key.code[ZP])
		set_projection_matrix(&env->sim.projection, env->cam.fov -= 1, env->win.ratio, 0.001f, 100.0f);
	if (env->key.code[ZM])
		set_projection_matrix(&env->sim.projection, env->cam.fov += 1, env->win.ratio, 0.001f, 100.0f);
}

void	camera_move(t_env *env)
{
	t_vec4	old;

	vec4_copy(&old, &env->cam.pos);
	if (env->key.code[TF])
		env->cam.pos = vec3_sub(env->cam.pos, vec3_fmul(env->cam.front, 0.02));
	if (env->key.code[TB])
		env->cam.pos = vec3_add(env->cam.pos, vec3_fmul(env->cam.front, 0.02));
	if (env->key.code[TL])
		env->cam.pos = vec3_sub(env->cam.pos, vec3_fmul(env->cam.right, 0.02));
	if (env->key.code[TR])
		env->cam.pos = vec3_add(env->cam.pos, vec3_fmul(env->cam.right, 0.02));
	if (env->key.code[TU])
		env->cam.pos = vec3_add(env->cam.pos, vec3_fmul(env->cam.up, 0.02));
	if (env->key.code[TD])
		env->cam.pos = vec3_sub(env->cam.pos, vec3_fmul(env->cam.up, 0.02));
	// env->cam.target = vec3_add(env->cam.target, vec3_sub(env->cam.pos, old));
}

void	camera_rotate(t_env *env)
{
	// if (env->key.code[GLFW_KEY_X])
		// env->cam.dir = vec3_rotate(env->cam.dir, (t_vec4){1, 0, 0, 1});
	// if (env->key.code[GLFW_KEY_C])
		// env->cam.dir = vec3_rotate(env->cam.dir, (t_vec4){-1, 0, 0, 1});
}

void	camera_look_at(t_env *env)
{

}
