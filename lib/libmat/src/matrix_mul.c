/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:38:04 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 18:26:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

/*	Matrix multiplication between A and B.
	for this operation one dimension must be common between A and B, ex:
	A(5, 3) and B(3, 8) is correct because the dimensions (5, 3) * (3, 8) = (5, 8)
	A(8, 2) and B(8, 2) is incorrect.
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
				tmp += A->data[h][z] * B->data[z][w];
			M.data[h][w] = tmp;
		}
	}
	return (M);
}
