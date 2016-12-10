/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:13:41 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 12:27:35 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	clean_glfw(t_env *env)
{
	glDeleteVertexArrays(1, &env->buffer.vao);
	glDeleteBuffers(1, &env->buffer.vbo);
	glDeleteBuffers(1, &env->buffer.ebo);
	glfwTerminate();
}

int		array_len(void **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}
/*
	GLfloat vertices[] = {
		-0.1f,  0.1f, -0.1f,  0.0f, 1.0f, 0.0f, // 0
		 0.1f,  0.1f, -0.1f,  0.0f, 0.0f, 1.0f, // 1
		 0.1f, -0.1f, -0.1f,  1.0f, 0.0f, 0.0f, // 2
		-0.1f, -0.1f, -0.1f,  0.0f, 1.0f, 1.0f, // 3
		-0.1f,  0.1f,  0.1f,  0.0f, 1.0f, 0.0f, // 4
		 0.1f,  0.1f,  0.1f,  0.0f, 0.0f, 1.0f, // 5
		 0.1f, -0.1f,  0.1f,  1.0f, 0.0f, 0.0f, // 6
		-0.1f, -0.1f,  0.1f,  0.0f, 1.0f, 1.0f  // 7
	};

	GLuint	indices[] = {
		0, 1, 2,  0, 3, 2,  0, 4, 5,  0, 1, 5,  0, 4, 7,  0, 3, 7,
		6, 2, 1,  6, 5, 1,  6, 5, 4,  6, 7, 4,  6, 2, 3,  6, 7, 3
	};
*/
