/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:23:16 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 18:45:31 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	translate(t_mat4 *m, t_vec3 v)
{
	m->m[3] += v.v[0];
	m->m[7] += v.v[1];
	m->m[11] += v.v[2];
}

void	rotate(t_mat4 *m, t_vec3 v)
{
	if (v.v[0] != 0.0)
		*m = mat4_rotate_axis(*m, AXIS_X, v.v[0]);
	if (v.v[1] != 0.0)
		*m = mat4_rotate_axis(*m, AXIS_Y, v.v[1]);
	if (v.v[2] != 0.0)
		*m = mat4_rotate_axis(*m, AXIS_Z, v.v[2]);
}

void	model_move_inertia(t_env *env, float inertia)
{
	env->model.inertia = vec3_fmul(env->model.inertia, inertia);
	if (env->key[TF].code)
		env->model.inertia = vec3_sub(env->model.inertia,
		vec3_fmul(vec3(env->cam.front.v[0], 0, env->cam.front.v[2]), 0.01));
	if (env->key[TB].code)
		env->model.inertia = vec3_add(env->model.inertia,
		vec3_fmul(vec3(env->cam.front.v[0], 0, env->cam.front.v[2]), 0.01));
	if (env->key[TL].code)
		env->model.inertia = vec3_sub(env->model.inertia,
		vec3_fmul(env->cam.right, 0.01));
	if (env->key[TR].code)
		env->model.inertia = vec3_add(env->model.inertia,
		vec3_fmul(env->cam.right, 0.01));
	if (env->key[TU].code)
		env->model.inertia = vec3_add(env->model.inertia,
		vec3_fmul(env->cam.up, 0.01));
	if (env->key[TD].code)
		env->model.inertia = vec3_sub(env->model.inertia,
		vec3_fmul(env->cam.up, 0.01));
	translate(&env->model.translation, env->model.inertia);
}

void	model_move_demo(t_env *env)
{
	if (env->key[RM].code)
		env->model.velocity -= 0.05;
	if (env->key[RP].code)
		env->model.velocity += 0.05;
	rotate(&env->model.rotation, vec3(0, env->model.velocity, 0));
}
