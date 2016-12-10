/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:46:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 18:40:28 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

t_vec3	vec3(float x, float y, float z)
{
	t_vec3	new;

	new.v[0] = x;
	new.v[1] = y;
	new.v[2] = z;
	return (new);
}

t_vec4	vec4(float x, float y, float z, float w)
{
	t_vec4	new;

	new.v[0] = x;
	new.v[1] = y;
	new.v[2] = z;
	new.v[3] = w;
	return (new);
}
