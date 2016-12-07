/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:34:09 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 12:30:29 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

// t_vec4 	vec3_rotate(t_vec4 v, float x, float y, float z)
t_vec4 	vec3_rotate(t_vec4 v, t_vec4 axis)
{
	t_vec4 	tmp;

	vec4_copy(&tmp, &v);
	if (axis.z != 0.0)
	{
		axis.z *= (M_PI / 180);
		tmp.x = v.x * cos(axis.z) - v.y * sin(axis.z);
		tmp.y = v.x * sin(axis.z) + v.y * cos(axis.z);
	}
	if (axis.y != 0.0)
	{
		axis.y *= (M_PI / 180);
		tmp.x = v.x * cos(axis.y) - v.z * sin(axis.y);
		tmp.z = v.x * sin(axis.y) + v.z * cos(axis.y);
	}
	if (axis.x != 0.0)
	{
		axis.x *= (M_PI / 180);
		tmp.y = v.y * cos(axis.x) - v.z * sin(axis.x);
		tmp.z = v.y * sin(axis.x) + v.z * cos(axis.x);
	}
	vec4_copy(&v, &tmp);
	return (v);
}