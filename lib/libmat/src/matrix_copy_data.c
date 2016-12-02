/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_copy_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:26:17 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 18:33:13 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

/*
**	Copy the data of matrix b in matrix a.
**	Both matrices should have the same dimensions.
*/
void	matrix_copy_data(t_mat *a, t_mat *b)
{
	int i;

	// if (a->size_h != b->size_h || a->size_w != b->size_w)
		// matrix_error(EXIT, MaTRIX_COPY_DaTa_ERR);
	a->size_w = b->size_w;
	a->size_h = b->size_h;
	// a->data = (float*)realloc(&a->data, sizeof(float) * b->size_h * b->size_w);
	i = -1;
	while (++i < a->size_h * a->size_w)
		a->data[i] = b->data[i];
}
