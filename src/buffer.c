/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:32:58 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/08 10:25:58 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_buffers(t_env *env, int mode)
{
	glGenBuffers(1, &env->buffer.VBO);
	glGenBuffers(1, &env->buffer.EBO);
	glGenVertexArrays(1, &env->buffer.VAO);
	glBindVertexArray(env->buffer.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, env->buffer.VBO);
	glBufferData(GL_ARRAY_BUFFER, env->model.size_vertices, env->model.vertices, mode);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->buffer.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, env->model.size_indices, env->model.indices, mode);
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	/* Color attributes */
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
}
