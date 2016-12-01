/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:13:11 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 18:27:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	matrix_add(t_mat *A, t_mat *B)
{
	int		h;
	int		w;
	t_mat	M;

	if (A->size_h != B->size_h || A->size_w != B->size_w)
		matrix_error(EXIT, MATRIX_ADDITION_ERR);
	M = matrix_create(A->size_h, A->size_w, 0);
	h = -1;
	while (++h < A->size_h)
	{
		w = -1;
		while (++w < A->size_w)
			M.data[h][w] = A->data[h][w] + B->data[h][w];
	}
	return (M);
}
