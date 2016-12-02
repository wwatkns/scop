/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:38:04 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 18:05:01 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

/*	Multiply the matrix a data with the matrix b.
	They should have their "link" dimension in common such as (4, 2).(2, 6)
*/
t_mat	matrix_mul(t_mat *a, t_mat *b)
{
	int		h;
	int		w;
	int		z;
	float	tmp;
	t_mat	m;

	if (a->size_w != b->size_h)
		matrix_error(EXIT, MATRIX_MULTIPLICATION_ERR);
	m = matrix_create(a->size_h, b->size_w, 0);
	h = -1;
	while (++h < a->size_h)
	{
		w = -1;
		while (++w < b->size_w)
		{
			z = -1;
			tmp = 0.0f;
			while (++z < a->size_w)
				tmp += a->data[h * a->size_w + z] * b->data[z * b->size_w + w];
			m.data[h * b->size_w + w] = tmp;
		}
	}
	matrix_copy_data(a, &m);
	matrix_delete(&m);
	return (*a);
}
