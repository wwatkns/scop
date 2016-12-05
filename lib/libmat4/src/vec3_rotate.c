/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:34:09 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/05 12:35:40 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

t_vec4 	vec3_rotate(t_vec4 v, float x, float y, float z)
{
	t_vec4 	tmp;

	vec4_copy(&tmp, &v);
	if (z != 0.0)
	{
		z *= (M_PI / 180);
		tmp.x = v.x * cos(z) - v.y * sin(z);
		tmp.y = v.x * sin(z) + v.y * cos(z);
	}
	if (y != 0.0)
	{
		y *= (M_PI / 180);
		tmp.x = v.x * cos(y) - v.z * sin(y);
		tmp.z = v.x * sin(y) + v.z * cos(y);
	}
	if (x != 0.0)
	{
		x *= (M_PI / 180);
		tmp.y = v.y * cos(x) - v.z * sin(x);
		tmp.z = v.y * sin(x) + v.z * cos(x);
	}
	vec4_copy(&v, &tmp);
	return (v);
}
