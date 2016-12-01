/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:53:55 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 17:52:38 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void	matrix_delete(t_mat *mat)
{
	int	h;

	h = -1;
	while (++h < mat->size_h)
		free(mat->data[h]);
	free(mat->data);
	*mat->data = NULL;
}
