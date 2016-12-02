/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:05:14 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 11:12:05 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	matrix_transpose(t_mat *A)
{
	int		h;
	int		w;
	int		z;
	float	tmp;
	t_mat	M;

	if (A->size_h <= 0 || A->size_w <= 0)
		matrix_error(EXIT, MATRIX_TRANSPOSE_ERR);
	M = matrix_create(A->size_w, A->size_h, 0);
	h = -1;
	while (++h < A->size_h)
	{
		w = -1;
		while (++w < A->size_w)
			M.data[w * A->size_h + h] = A->data[h * A->size_w + w];
	}
	return (M);
}
