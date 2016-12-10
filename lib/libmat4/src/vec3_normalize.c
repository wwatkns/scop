/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:02:10 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 18:41:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

t_vec3	vec3_normalize(t_vec3 v)
{
	float	magnitude;

	magnitude = vec3_magnitude(v);
	v.v[0] /= magnitude;
	v.v[1] /= magnitude;
	v.v[2] /= magnitude;
	return (v);
}
