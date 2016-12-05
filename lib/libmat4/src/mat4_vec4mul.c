/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_vec4mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:52:13 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/05 16:48:51 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

void	mat4_vec4mul(t_vec4 *a, t_mat4 *b)
{
	int		h;
	int		w;
	int		z;
	t_vec4 	tmp;

	h = -1;
	while (++h < 1)
	{
		w = -1;
		while (++w < 4)
		{
			z = -1;
			tmp.v[h * 4 + w] = 0;
			while (++z < 4)
				tmp.v[h * 4 + w] += a->v[h * 4 + z] * b->m[z * 4 + w];
		}
	}
	vec4_copy(a, &tmp);
}
