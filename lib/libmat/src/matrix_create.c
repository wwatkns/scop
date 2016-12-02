/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:38:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 11:26:38 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	matrix_create(int size_h, int size_w, float val)
{
	t_mat	M;
	int		w;
	int		h;

	M.size_h = size_h;
	M.size_w = size_w;
	M.data = (float*)malloc(sizeof(float) * size_h * size_w);
	h = 0;
	while (h < size_h * size_w)
	{
		w = -1;
		while (++w < size_w)
			M.data[h + w] = val;
		h += size_w;
	}
	return (M);
}
