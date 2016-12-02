/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:09:58 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 18:20:07 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void	matrix_print(t_mat *m)
{
	int h;
	int	w;

	h = 0;
	while (h < m->size_h * m->size_w)
	{
		printf("[ ");
		w = -1;
		while (++w < m->size_w)
			printf("%.3f ", m->data[h + w]);
		printf("]\n");
		h += m->size_w;
	}
	printf("\n");
}
