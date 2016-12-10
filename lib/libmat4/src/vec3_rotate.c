/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:34:09 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 18:42:16 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

t_vec3	vec3_rotate(t_vec3 v, t_vec3 axis)
{
	t_vec3	tmp;

	vec3_copy(&tmp, &v);
	if (axis.v[2] != 0.0)
	{
		axis.v[2] *= (M_PI / 180);
		tmp.v[0] = v.v[0] * cos(axis.v[2]) - v.v[1] * sin(axis.v[2]);
		tmp.v[1] = v.v[0] * sin(axis.v[2]) + v.v[1] * cos(axis.v[2]);
	}
	if (axis.v[1] != 0.0)
	{
		axis.v[1] *= (M_PI / 180);
		tmp.v[0] = v.v[0] * cos(axis.v[1]) - v.v[2] * sin(axis.v[1]);
		tmp.v[2] = v.v[0] * sin(axis.v[1]) + v.v[2] * cos(axis.v[1]);
	}
	if (axis.v[0] != 0.0)
	{
		axis.v[0] *= (M_PI / 180);
		tmp.v[1] = v.v[1] * cos(axis.v[0]) - v.v[2] * sin(axis.v[0]);
		tmp.v[2] = v.v[1] * sin(axis.v[0]) + v.v[2] * cos(axis.v[0]);
	}
	vec3_copy(&v, &tmp);
	return (v);
}
