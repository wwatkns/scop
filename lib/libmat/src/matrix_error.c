/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 18:25:49 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void	matrix_error(int exit_program, int error)
{
	if (error == MATRIX_ADDITION_ERR)
		printf("ERROR: matrix ADDITION, invalid dimensions.");
	else if (error == MATRIX_SUBSTRACTION_ERR)
		printf("ERROR: matrix SUBSTRACTION, invalid dimensions.");
	else if (error == MATRIX_MULTIPLICATION_ERR)
		printf("ERROR: matrix MULTIPLICATION, invalid dimensions.");
	else if (error == MATRIX_TRANSPOSE_ERR)
		printf("ERROR: matrix TRANSPOSE, invalid dimensions.");
	if (exit_program)
		exit(0);
}
