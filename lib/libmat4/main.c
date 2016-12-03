/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:01:52 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/03 11:58:55 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

int	main(void)
{
	float	a[16];

	mat4_set(a, IDENTITY);

	mat4_print(a);

	mat4_rotate_axis(a, AXIS_X, 45);
	mat4_print(a);

	return (0);
}
