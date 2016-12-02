/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:01:52 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/02 13:46:34 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void	print_matrix(t_mat *mat)
{
	for (int h = 0; h < mat->size_h; h++)
	{
		printf("[ ");
		for (int w = 0; w < mat->size_w; w++)
			printf("%.3f ", mat->data[h * mat->size_w + w]);
		printf("]\n");
	}
	printf("\n");
}

int	main(void)
{
	t_mat	A;
	t_mat	B;
	t_mat	C;

	A = matrix_create(1, 4, 1);
	A.data[3] = 1;
	print_matrix(&A);
	A = matrix_rotate_axis(&A, AXIS_Z, 45);
	// A = matrix_rotate_axis(&A, AXIS_Y, 45);
	print_matrix(&A);

	// A = matrix_create(4, 2, 1);
	// A = matrix_create(2, 3, 1);
	// B = matrix_create(2, 3, 3.2);
	// A.data[0] = 7;
	// A.data[1] = 2;
	// print_matrix(&A);
	// B.data[0] = 4.1;
	// B.data[2] = 0.5;
	// print_matrix(&B);
	//
	// A = matrix_add(&A, &B);
	// print_matrix(&A);
	// A = matrix_scale(&A, 0.1f);
	// print_matrix(&A);

	// B.data[0] = 3.5;
	// B.data[1] = 4;
	// B = matrix_transpose(&B);
	// print_matrix(&B);
	//
	// C = matrix_mul(&A, &B);
	// print_matrix(&C);
	//
	// C = matrix_create(3, 2, 1);
	// C.data[1] = 2;
	// C.data[2] = 3;
	// C.data[3] = 4;
	// C.data[4] = 5;
	// C.data[5] = 6;
	// print_matrix(&C);
	// matrix_transpose(&C);
	// print_matrix(&C);
	//
	// t_mat M = matrix_copy(&C);
	// M.data[0] = 99.99;
	// print_matrix(&M);

	// while (1)
		// matrix_transpose(&C);

	// matrix_delete(&A);
	// matrix_delete(&B);
	// matrix_delete(&C);
	return (0);
}
