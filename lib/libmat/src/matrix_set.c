/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:19:39 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 15:24:46 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void	matrix_set(t_mat *m, int type)
{
	int	h;
	int	w;

	if (type == IDENTITY && m->size_w == m->size_h)
	{
		h = 0;
		w = 0;
		while (h < m->size_h * m->size_w)
		{
			m->data[h + w] = 1;
			w++;
			h += m->size_w;
		}
	}
}
