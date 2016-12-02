/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:55:01 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 13:50:26 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	build_axis_x_rotation_matrix(float theta)
{
	t_mat	R;

	R = matrix_create(4, 4, 0);
	R.data[0] = 1;
	R.data[5] = cos(theta);
	R.data[6] = sin(theta);
	R.data[9] = -sin(theta);
	R.data[10] = cos(theta);
	R.data[15] = 1;
	return (R);
}

t_mat	build_axis_y_rotation_matrix(float theta)
{
	t_mat	R;

	R = matrix_create(4, 4, 0);
	R.data[0] = cos(theta);
	R.data[2] = -sin(theta);
	R.data[5] = 1;
	R.data[8] = sin(theta);
	R.data[10] = cos(theta);
	R.data[15] = 1;
	return (R);
}

t_mat	build_axis_z_rotation_matrix(float theta)
{
	t_mat	R;

	R = matrix_create(4, 4, 0);
	R.data[0] = cos(theta);
	R.data[1] = sin(theta);
	R.data[4] = -sin(theta);
	R.data[5] = cos(theta);
	R.data[10] = 1;
	R.data[15] = 1;
	return (R);
}

t_mat	matrix_rotate_axis(t_mat *M, int axis, float angle)
{
	t_mat	R;
	float	theta;

	theta = angle * (PI / 180);
	if (axis == AXIS_X)
		R = build_axis_x_rotation_matrix(theta);
	else if (axis == AXIS_Y)
		R = build_axis_y_rotation_matrix(theta);
	else if (axis == AXIS_Z)
		R = build_axis_z_rotation_matrix(theta);
	R = matrix_mul(M, &R);
	matrix_copy_data(M, &R);
	// matrix_delete(&R);
	return (*M);
}
