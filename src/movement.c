/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:23:16 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/08 17:21:21 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	translate(t_mat4 *m, t_vec3 v)
{
	m->tx += v.x;
	m->ty += v.y;
	m->tz += v.z;
}

void	scale(t_mat4 *m, t_vec3 v)
{
	m->sx += v.x;
	m->sy += v.y;
	m->sz += v.z;
}

void	rotate(t_mat4 *m, t_vec3 v)
{
	if (v.x != 0.0)
		*m = mat4_rotate_axis(*m, AXIS_X, v.x);
	if (v.y != 0.0)
		*m = mat4_rotate_axis(*m, AXIS_Y, v.y);
	if (v.z != 0.0)
		*m = mat4_rotate_axis(*m, AXIS_Z, v.z);
}

void	model_move_inertia(t_env *env, float inertia)
{
	env->model.inertia = vec3_fmul(env->model.inertia, inertia);
	if (env->key[TF].code)
		env->model.inertia = vec3_sub(env->model.inertia,
		vec3_fmul(vec3(env->cam.front.x, 0, env->cam.front.z), 0.01));
	if (env->key[TB].code)
		env->model.inertia = vec3_add(env->model.inertia,
		vec3_fmul(vec3(env->cam.front.x, 0, env->cam.front.z), 0.01));
	if (env->key[TL].code)
		env->model.inertia = vec3_sub(env->model.inertia, vec3_fmul(env->cam.right, 0.01));
	if (env->key[TR].code)
		env->model.inertia = vec3_add(env->model.inertia, vec3_fmul(env->cam.right, 0.01));
	if (env->key[TU].code)
		env->model.inertia = vec3_add(env->model.inertia, vec3_fmul(env->cam.up, 0.01));
	if (env->key[TD].code)
		env->model.inertia = vec3_sub(env->model.inertia, vec3_fmul(env->cam.up, 0.01));
	translate(&env->model.translation, env->model.inertia);
}

void	model_move_demo(t_env *env)
{
	// rotate(&env->sim.model, vec3(0, 0.1, 0));
}
