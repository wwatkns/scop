/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:39:48 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 18:04:23 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	matrix_copy(t_mat *m)
{
	int		i;
	t_mat	c;

	i = -1;
	c = matrix_create(m->size_h, m->size_w, 0);
	while (++i < m->size_h * m->size_w)
		c.data[i] = m->data[i];
	return (c);
}
