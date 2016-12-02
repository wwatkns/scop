/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:27:51 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 19:23:11 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat	create_model_matrix(void)
{
	t_mat	m;

	m = matrix_create(4, 4, 0);
	matrix_set(&m, IDENTITY);
	return (m);
}

t_mat	create_view_matrix(void)
{
	t_mat	m;

	m = matrix_create(4, 4, 0);
	matrix_set(&m, IDENTITY);
	return (m);
}

t_mat	create_projection_matrix(float fov, float ratio, float near, float far)
{
	float	s;
	t_mat	m;

	s = 1 / (tan(fov * 0.5 * M_PI / 180.0));
	m = matrix_create(4, 4, 0);
	m.data[0] = s / ratio;
	m.data[5] = s;
	m.data[10] = -(far + near) / (far - near);
	m.data[11] = -1;
	m.data[14] = -2 * far * near / (far - near);
	m.data[15] = 1;
	return (m);
}
