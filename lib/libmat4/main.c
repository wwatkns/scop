/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:01:52 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/05 12:30:07 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

int	main(void)
{
	// t_mat4	a;

	// mat4_set(&a, IDENTITY);
	// mat4_print(&a);
	// mat4_rotate_axis(&a, AXIS_X, 45);
	// mat4_print(&a);

	t_vec4 	a;
	t_vec4 	b;

	a = (t_vec4 ) { 1, 4.5, 2, 1 };
	vec4_print(a);
	b = (t_vec4 ) { 1, 1, 1, 1 };
	vec4_print(a);

	b = vec3_add(a, b);
	vec4_print(b);
	// vec3_set(&b, 0);
	// b.x = 2;
	// vec4_print(&b);
	//
	// vec3_scale(&a, 1.0);
	//
	// vec4_print(&a);

	return (0);
}
