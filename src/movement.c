/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:23:16 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 14:41:11 by wwatkins         ###   ########.fr       */
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

// void	rotate(t_mat4 *m, float theta, t_vec3 v)
// {
// 	float	c;
// 	float	s;
// 	t_mat4	r;
//
// 	mat4_set(&r, IDENTITY);
// 	theta *= (M_PI / 180);
// 	c = cos(theta);
// 	s = sin(theta);
// 	r.m[0] = v.x * v.x + (1 - v.x * v.x) * c;
// 	r.m[1] = v.x * v.y * (1 - c) - v.z * s;
// 	r.m[2] = v.x * v.z * (1 - c) + v.y * s;
// 	r.m[4] = v.x * v.y * (1 - c) + v.z * s;
// 	r.m[5] = v.y * v.y + (1 - v.y * v.y) * c;
// 	r.m[6] = v.y * v.z * (1 - c) - v.x * s;
// 	r.m[8] = v.x * v.z * (1 - c) - v.y * s;
// 	r.m[9] = v.y * v.z * (1 - c) + v.x * s;
// 	r.m[10]= v.z * v.z + (1 - v.z * v.z) * c;
// 	// mat4_copy(m, r);
// 	*m = mat4_mul(*m, r);
// }

t_mat4	look_at(t_env *env, t_vec4 *from, t_vec4 *to, t_vec4 *up)
{
	t_vec4	y;
	t_mat4	view;

	env->cam.front = vec3_normalize(vec3_sub(*from, *to));
	env->cam.right = vec3_normalize(vec3_cross(*up, env->cam.front));
	y = vec3_cross(env->cam.front, env->cam.right);
	mat4_set(&view, IDENTITY);
	view.m[0] = env->cam.right.x;
	view.m[1] = y.x;
	view.m[2] = env->cam.front.x;
	view.m[4] = env->cam.right.y;
	view.m[5] = y.y;
	view.m[6] = env->cam.front.y;
	view.m[8] = env->cam.right.z;
	view.m[9] = y.z;
	view.m[10]= env->cam.front.z;
	view.m[12]= -vec3_dot(env->cam.right, *from);
	view.m[13]= -vec3_dot(y, *from);
	view.m[14]= -vec3_dot(env->cam.front, *from);
	return (view);
}
