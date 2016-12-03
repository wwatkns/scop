/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:54:24 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/03 11:52:55 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMAT4_H
# define LIBMAT4_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define MATRIX_ADDITION_ERR 0
# define MATRIX_SUBSTRACTION_ERR 1
# define MATRIX_MULTIPLICATION_ERR 2
# define MATRIX_TRANSPOSE_ERR 3
# define MATRIX_COPY_DATA_ERR 4

# define STAY 0
# define EXIT 1

# define AXIS_X 0
# define AXIS_Y 1
# define AXIS_Z 2

# define PI 3.1415926

# define IDENTITY 0x7FFFFFFF

void	mat4_set(float *m, float f);

void	mat4_copy(float *a, float *b);

void	mat4_print(float *m);
void	mat4_error(int exit, int error);

void	mat4_add(float *a, float *b);
void	mat4_sub(float *a, float *b);
void	mat4_mul(float *a, float *b);
void	mat4_scale(float *m, float f);

void	mat4_transpose(float *m);
void	mat4_rotate_axis(float *m, int axis, float angle);

#endif
