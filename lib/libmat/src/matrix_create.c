/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:38:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 18:04:48 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	matrix_create(int size_h, int size_w, double val)
{
	t_mat	mat;
	int		w;
	int		h;

	mat.size_h = size_h;
	mat.size_w = size_w;
	mat.data = (double**)malloc(sizeof(double*) * size_h);
	h = -1;
	while (++h < size_h)
	{
		mat.data[h] = (double*)malloc(sizeof(double) * size_w);
		w = -1;
		while (++w < size_w)
			mat.data[h][w] = val;
	}
	return (mat);
}
