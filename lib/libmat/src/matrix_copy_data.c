/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_copy_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:26:17 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 12:44:14 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

/*	Copy the data of matrix B in matrix A.
	Both matrices should have the same dimensions.
*/
void	matrix_copy_data(t_mat *A, t_mat *B)
{
	int i;

	if (A->size_h != B->size_h || A->size_w != B->size_w)
		matrix_error(EXIT, MATRIX_COPY_DATA_ERR);
	i = -1;
	while (++i < A->size_h * A->size_w)
		A->data[i] = B->data[i];
}
