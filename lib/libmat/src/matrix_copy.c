/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:39:48 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 11:42:42 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat	matrix_copy(t_mat *M)
{
	int		i;
	t_mat	C;

	i = -1;
	C = matrix_create(M->size_h, M->size_w, 0);
	while (++i < M->size_h * M->size_w)
		C.data[i] = M->data[i];
	return (C);
}
