/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:38:04 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 12:29:20 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

/*	Multiply the matrix A data with the matrix B.
	They should have their "link" dimension in common such as (4, 2).(2, 6)
*/
t_mat	matrix_mul(t_mat *A, t_mat *B)
{
	int		h;
	int		w;
	int		z;
	float	tmp;
	t_mat	M;

	if (A->size_w != B->size_h)
		matrix_error(EXIT, MATRIX_MULTIPLICATION_ERR);
	M = matrix_create(A->size_h, B->size_w, 0);
	h = -1;
	while (++h < A->size_h)
	{
		w = -1;
		while (++w < B->size_w)
		{
			z = -1;
			tmp = 0.0f;
			while (++z < A->size_w)
				tmp += A->data[h * A->size_w + z] * B->data[z * B->size_w + w];
			M.data[h * B->size_w + w] = tmp;
		}
	}
	matrix_copy_data(A, &M);
	matrix_delete(&M);
	return (*A);
}
