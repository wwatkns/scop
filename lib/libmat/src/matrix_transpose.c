/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:05:14 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 12:47:03 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	matrix_transpose(t_mat *M)
{
	int		h;
	int		w;
	int		z;
	float	tmp;
	t_mat	T;

	if (M->size_h <= 0 || M->size_w <= 0)
		matrix_error(EXIT, MATRIX_TRANSPOSE_ERR);
	T = matrix_create(M->size_w, M->size_h, 0);
	h = -1;
	while (++h < M->size_h)
	{
		w = -1;
		while (++w < M->size_w)
			T.data[w * M->size_h + h] = M->data[h * M->size_w + w];
	}
	M->size_h = T.size_h;
	M->size_w = T.size_w;
	matrix_copy_data(M, &T);
	matrix_delete(&T);
	return (*M);
}
