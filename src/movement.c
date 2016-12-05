/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:23:16 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/05 13:18:03 by wwatkins         ###   ########.fr       */
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
//
// void	rotate(t_mat4 *m, float theta, t_vec4 axis)
// {
//
// }

// void	rotate(t_mat4 *m, float x, float y, float z)
// {
// 	if (x != 0)
// 		mat4_rotate_axis(m, AXIS_X, x);
// 	if (y != 0)
// 		mat4_rotate_axis(m, AXIS_Y, y);
// 	if (z != 0)
// 		mat4_rotate_axis(m, AXIS_Z, z);
// }

t_mat4	look_at(t_vec4 *from, t_vec4 *to)
{
	t_vec4	x;
	t_vec4	y;
	t_vec4	z;
	t_vec4	up;
	t_mat4	view;

	up = (t_vec4) { 0, -1, 0, 1 };
	z = vec3_normalize(vec3_sub(*from, *to));
	x = vec3_normalize(vec3_cross(up, z));
	y = vec3_cross(z, x);

	view = (t_mat4) {
			x.x,				y.x,				z.x,		   0,
			x.y,				y.y,				z.y,		   0,
			x.z,				y.z,				z.z,		   0,
	-vec3_dot(x, *from), -vec3_dot(y, *from), -vec3_dot(z, *from), 1
	};
	return (view);
}
