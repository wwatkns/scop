/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:55:01 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 18:07:24 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void	get_axis_x_rotation_matrix(t_mat *m, float theta)
{
	m->data[0] = 1;
	m->data[5] = cos(theta);
	m->data[6] = sin(theta);
	m->data[9] = -sin(theta);
	m->data[10] = cos(theta);
	m->data[15] = 1;
}

void	get_axis_y_rotation_matrix(t_mat *m, float theta)
{
	m->data[0] = cos(theta);
	m->data[2] = -sin(theta);
	m->data[5] = 1;
	m->data[8] = sin(theta);
	m->data[10] = cos(theta);
	m->data[15] = 1;
}

void	get_axis_z_rotation_matrix(t_mat *m, float theta)
{
	m->data[0] = cos(theta);
	m->data[1] = sin(theta);
	m->data[4] = -sin(theta);
	m->data[5] = cos(theta);
	m->data[10] = 1;
	m->data[15] = 1;
}

t_mat	matrix_rotate_axis(t_mat *m, int axis, float angle)
{
	t_mat	r;
	float	theta;

	r = matrix_create(4, 4, 0);
	theta = angle * (M_PI / 180);
	if (axis == AXIS_X)
		get_axis_x_rotation_matrix(&r, theta);
	else if (axis == AXIS_Y)
		get_axis_y_rotation_matrix(&r, theta);
	else if (axis == AXIS_Z)
		get_axis_z_rotation_matrix(&r, theta);
	r = matrix_mul(m, &r);
	matrix_copy_data(m, &r);
	// matrix_delete(&r);
	return (*m);
}
