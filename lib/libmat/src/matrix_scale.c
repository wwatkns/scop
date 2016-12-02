/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:51:46 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 12:53:02 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	matrix_scale(t_mat *M, float scalar)
{
	int	i;

	i = -1;
	while (++i < M->size_h * M->size_w)
		M->data[i] *= scalar;
	return (*M);
}
