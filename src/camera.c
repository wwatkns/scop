/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:13:45 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 12:11:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	camera_zoom(t_env *env)
{
	if (env->key[ZP].code)
		set_projection_matrix(&env->sim.projection,
		env->cam.fov -= 1, env->win.ratio, 0.001f, 100.0f);
	if (env->key[ZM].code)
		set_projection_matrix(&env->sim.projection,
		env->cam.fov += 1, env->win.ratio, 0.001f, 100.0f);
}

void	camera_move_inertia(t_env *env, float inertia, int mode)
{
	t_vec3	old;

	env->cam.inertia = vec3_fmul(env->cam.inertia, inertia);
	vec3_copy(&old, &env->cam.pos);
	if (env->key[CF].code)
		env->cam.inertia = vec3_sub(env->cam.inertia,
		vec3_fmul(env->cam.front, env->cam.velocity));
	if (env->key[CB].code)
		env->cam.inertia = vec3_add(env->cam.inertia,
		vec3_fmul(env->cam.front, env->cam.velocity));
	if (env->key[CL].code)
		env->cam.inertia = vec3_sub(env->cam.inertia,
		vec3_fmul(env->cam.right, env->cam.velocity));
	if (env->key[CR].code)
		env->cam.inertia = vec3_add(env->cam.inertia,
		vec3_fmul(env->cam.right, env->cam.velocity));
	if (env->key[CU].code)
		env->cam.inertia = vec3_add(env->cam.inertia,
		vec3_fmul(env->cam.up, env->cam.velocity));
	if (env->key[CD].code)
		env->cam.inertia = vec3_sub(env->cam.inertia,
		vec3_fmul(env->cam.up, env->cam.velocity));
	env->cam.pos = vec3_add(env->cam.pos, env->cam.inertia);
	if (mode == FREE)
		env->cam.target = vec3_add(env->cam.target, vec3_sub(env->cam.pos, old));
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
	view.m[10]= env->cam.front.z;
	view.m[12]= -vec3_dot(env->cam.right, env->cam.pos);
	view.m[13]= -vec3_dot(tmp, env->cam.pos);
	view.m[14]= -vec3_dot(env->cam.front, env->cam.pos);
	env->sim.view = view;
}
