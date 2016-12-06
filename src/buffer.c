/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:32:58 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 16:48:50 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_buffers(t_env *env, GLfloat *vertices, GLuint *indices, int mode)
{
	glGenBuffers(1, &env->buffer.VBO);
	glGenBuffers(1, &env->buffer.EBO);
	glGenVertexArrays(1, &env->buffer.VAO);
	/*	Binds the objects to the corresponding buffers with
		the vertex_array_object first */
	glBindVertexArray(env->buffer.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, env->buffer.VBO);
	glBufferData(GL_ARRAY_BUFFER, env->model.size_vertices, vertices, mode);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->buffer.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, env->model.size_indices, indices, mode);
	/* Position attributes */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	/* Color attributes */
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
}
