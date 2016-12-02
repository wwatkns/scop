/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:05:14 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 19:24:49 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	matrix_transpose(t_mat *m)
{
	int		h;
	int		w;
	float	tmp;
	t_mat	t;

	if (m->size_h <= 0 || m->size_w <= 0)
		matrix_error(EXIT, MATRIX_TRANSPOSE_ERR);
	t = matrix_create(m->size_w, m->size_h, 0);
	h = -1;
	while (++h < m->size_h)
	{
		w = -1;
		while (++w < m->size_w)
			t.data[w * m->size_h + h] = m->data[h * m->size_w + w];
	}
	m->size_h = t.size_h;
	m->size_w = t.size_w;
	matrix_copy_data(m, &t);
	matrix_delete(&t);
	return (*m);
}
