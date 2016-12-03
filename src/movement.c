/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:23:16 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/03 13:39:21 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	translate(float *m, float x, float y, float z)
{
	m[3] += x;
	m[7] += y;
	m[11] += z;
}

void	scale(float *m, float x, float y, float z)
{
	m[0] += x;
	m[5] += y;
	m[10] += z;
}

void	rotate(float *m, float x, float y, float z)
{
	if (x != 0)
		mat4_rotate_axis(m, AXIS_X, x);
	if (y != 0)
		mat4_rotate_axis(m, AXIS_Y, y);
	if (z != 0)
		mat4_rotate_axis(m, AXIS_Z, z);
}
// 
// void	look_at(float *m, float x, float y, float z)
// {
//
// }
