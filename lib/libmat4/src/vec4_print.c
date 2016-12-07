/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:13:29 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/05 12:36:54 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

void	vec4_print(t_vec4 *v)
{
	int i;

	i = -1;
	printf("[ ");
	while (++i < 4)
		printf("%.3f ", v->v[i]);
	printf("]\n\n");
}