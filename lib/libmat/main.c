/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:01:52 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 19:18:56 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void	print_matrix(t_mat *mat)
{
	for (int h = 0; h < mat->size_h; h++)
	{
		printf("[ ");
		for (int w = 0; w < mat->size_w; w++)
			printf("%.3f ", mat->data[h][w]);
		printf("]\n");
	}
	printf("\n");
}

int	main(void)
{
	t_mat	A;
	t_mat	B;
	t_mat	C;

	A = matrix_create(4, 2, 1);
	B = matrix_create(3, 2, -0.5);
	A.data[0][0] = 7;
	A.data[1][0] = 2;
	print_matrix(&A);

	B.data[0][0] = 3.5;
	B.data[1][0] = 4;
	print_matrix(&B);

	B = matrix_transpose(&B);
	C = matrix_mul(&A, &B);
	print_matrix(&C);

	// matrix_delete(&A);
	// matrix_delete(&B);
	// matrix_delete(&C);
	return (0);
}
