/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:55:01 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/03 12:02:14 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

void	get_axis_x_rotation_matrix(float *m, float theta)
{
	m[5] = cos(theta);
	m[6] = sin(theta);
	m[9] = -sin(theta);
	m[10] = cos(theta);
}

void	get_axis_y_rotation_matrix(float *m, float theta)
{
	m[0] = cos(theta);
	m[2] = -sin(theta);
	m[8] = sin(theta);
	m[10] = cos(theta);
}

void	get_axis_z_rotation_matrix(float *m, float theta)
{
	m[0] = cos(theta);
	m[1] = sin(theta);
	m[4] = -sin(theta);
	m[5] = cos(theta);
}

void	mat4_rotate_axis(float *m, int axis, float angle)
{
	float	r[16];
	float	theta;

	mat4_set(r, IDENTITY);
	theta = angle * (M_PI / 180);
	if (axis == AXIS_X)
		get_axis_x_rotation_matrix(r, theta);
	else if (axis == AXIS_Y)
		get_axis_y_rotation_matrix(r, theta);
	else if (axis == AXIS_Z)
		get_axis_z_rotation_matrix(r, theta);
	mat4_mul(m, r);
}
