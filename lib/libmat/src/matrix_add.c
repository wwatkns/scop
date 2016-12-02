/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:13:11 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 19:23:26 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	matrix_add(t_mat *a, t_mat *b)
{
	int		h;
	int		w;

	if (a->size_h != b->size_h || a->size_w != b->size_w)
		matrix_error(EXIT, MATRIX_ADDITION_ERR);
	h = 0;
	while (h < a->size_h * a->size_w)
	{
		w = -1;
		while (++w < a->size_w)
			a->data[h + w] += b->data[h + w];
		h += a->size_w;
	}
	return (*a);
}
