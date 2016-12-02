/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:31:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 13:41:52 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMAT_H
# define LIBMAT_H

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

typedef struct	s_mat
{
	int		size_h;
	int		size_w;
	float	*data;
}				t_mat;

t_mat	matrix_create(int size_h, int size_w, float val);
void	matrix_delete(t_mat *M);

t_mat	matrix_copy(t_mat *M);
void	matrix_copy_data(t_mat *A, t_mat *B);

void	matrix_error(int exit, int error);

t_mat	matrix_add(t_mat *A, t_mat *B);
t_mat	matrix_sub(t_mat *A, t_mat *B);
t_mat	matrix_mul(t_mat *A, t_mat *B);
t_mat	matrix_scale(t_mat *M, float scalar);

t_mat	matrix_transpose(t_mat *M);
t_mat	matrix_rotate_axis(t_mat *M, int axis, float angle);

#endif
