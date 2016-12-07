/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:23:16 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 16:34:16 by wwatkins         ###   ########.fr       */
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