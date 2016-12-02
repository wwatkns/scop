/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:51:46 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 16:11:05 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void	matrix_scale(t_mat *m, float scalar)
{
	int	i;

	i = -1;
	while (++i < m->size_h * m->size_w)
		m->data[i] *= scalar;
}
