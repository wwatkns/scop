/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:54:24 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/05 16:49:00 by wwatkins         ###   ########.fr       */
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

# define IDENTITY 0x7FFFFFFF

typedef struct	s_mat4
{
	union
	{
		struct
		{
			float sx, m1, m2, tx,
				  m4, sy, m6, ty,
				  m8, m9, sz, tz,
                  m12, m13, m14, m15;
		};
		float	m[16];
	};
}				t_mat4;

typedef struct	s_vec4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		float	v[4];
	};
}				t_vec4;

typedef struct	s_vec3
{
	union
	{
		struct
		{
			float x, y, z;
		};
		float	v[3];
	};
}				t_vec3;

/* Matrices
*/
void	mat4_set(t_mat4 *m, float f);

t_mat4	mat4_copy(t_mat4 *a, t_mat4 b);

void	mat4_print(t_mat4 *m);

t_mat4	mat4_add(t_mat4 a, t_mat4 b);
t_mat4	mat4_sub(t_mat4 a, t_mat4 b);
t_mat4	mat4_mul(t_mat4 a, t_mat4 b);
t_mat4	mat4_scale(t_mat4 m, float f);

t_mat4	mat4_transpose(t_mat4 *m);
t_mat4	mat4_rotate_axis(t_mat4 m, int axis, float angle);

/* Common
*/
void	mat4_vec4mul(t_vec4 *a, t_mat4 *b);

/* Vectors
*/
void	vec3_set(t_vec4 *v, float f);
t_vec4	vec4_copy(t_vec4 *a, t_vec4 *b);

t_vec4	vec3_add(t_vec4 a, t_vec4 b);
t_vec4	vec3_sub(t_vec4 a, t_vec4 b);
t_vec4	vec3_mul(t_vec4 a, t_vec4 b);
t_vec4	vec3_fmul(t_vec4 v, float f);
t_vec4	vec3_scale(t_vec4 v, float f);
t_vec4	vec3_cross(t_vec4 a, t_vec4 b);
t_vec4	vec3_rotate(t_vec4 v, float x, float y, float z);

float	vec3_dot(t_vec4 a, t_vec4 b);
float	vec3_magnitude(t_vec4 v);
t_vec4	vec3_normalize(t_vec4 v);

void	vec4_print(t_vec4 *v);

#endif
