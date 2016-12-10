/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:13:45 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 13:20:09 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	camera_zoom(t_env *env)
{
	if (env->key[ZP].code)
		set_projection_matrix(env, env->cam.fov -= 1, 0.001f, 100.0f);
	if (env->key[ZM].code)
		set_projection_matrix(env, env->cam.fov += 1, 0.001f, 100.0f);
}

void	camera_move_inertia(t_env *e, float inertia, int mode)
{
	t_vec3	old;

	e->cam.inertia = vec3_fmul(e->cam.inertia, inertia);
	vec3_copy(&old, &e->cam.pos);
	if (e->key[CF].code)
		e->cam.inertia = vec3_sub(e->cam.inertia,
		vec3_fmul(e->cam.front, e->cam.velocity));
	if (e->key[CB].code)
		e->cam.inertia = vec3_add(e->cam.inertia,
		vec3_fmul(e->cam.front, e->cam.velocity));
	if (e->key[CL].code)
		e->cam.inertia = vec3_sub(e->cam.inertia,
		vec3_fmul(e->cam.right, e->cam.velocity));
	if (e->key[CR].code)
		e->cam.inertia = vec3_add(e->cam.inertia,
		vec3_fmul(e->cam.right, e->cam.velocity));
	if (e->key[CU].code)
		e->cam.inertia = vec3_add(e->cam.inertia,
		vec3_fmul(e->cam.up, e->cam.velocity));
	if (e->key[CD].code)
		e->cam.inertia = vec3_sub(e->cam.inertia,
		vec3_fmul(e->cam.up, e->cam.velocity));
	e->cam.pos = vec3_add(e->cam.pos, e->cam.inertia);
	if (mode == FREE)
		e->cam.target = vec3_add(e->cam.target, vec3_sub(e->cam.pos, old));
}

void	camera_center(t_env *env)
{
	t_vec3	model_pos;

	model_pos.x = env->model.translation.tx;
	model_pos.y = env->model.translation.ty;
	model_pos.z = env->model.translation.tz;
	env->cam.target = vec3_add(env->model.center_axis, model_pos);
}

void	camera_look_at_target(t_env *env)
{
	t_vec3	tmp;
	t_mat4	view;

	tmp = env->cam.up;
	env->cam.front = vec3_normalize(vec3_sub(env->cam.pos, env->cam.target));
	env->cam.right = vec3_normalize(vec3_cross(env->cam.up, env->cam.front));
	tmp = vec3_cross(env->cam.front, env->cam.right);
	mat4_set(&view, IDENTITY);
	view.m[0] = env->cam.right.x;
	view.m[1] = tmp.x;
	view.m[2] = env->cam.front.x;
	view.m[4] = env->cam.right.y;
	view.m[5] = tmp.y;
	view.m[6] = env->cam.front.y;
	view.m[8] = env->cam.right.z;
	view.m[9] = tmp.z;
	view.m[10] = env->cam.front.z;
	view.m[12] = -vec3_dot(env->cam.right, env->cam.pos);
	view.m[13] = -vec3_dot(tmp, env->cam.pos);
	view.m[14] = -vec3_dot(env->cam.front, env->cam.pos);
	env->sim.view = view;
}
