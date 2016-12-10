/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:32:58 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 13:21:12 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_texture(t_env *env)
{
	glGenTextures(1, &env->buffer.texture);
	glBindTexture(GL_TEXTURE_2D, env->buffer.texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, env->model.texture.w,
	env->model.texture.h, 0, GL_RGB, GL_UNSIGNED_BYTE, env->model.texture.img);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void	create_buffers(t_env *env, int mode)
{
	glGenBuffers(1, &env->buffer.vbo);
	glGenBuffers(1, &env->buffer.ebo);
	glGenVertexArrays(1, &env->buffer.vao);
	glBindVertexArray(env->buffer.vao);
	glBindBuffer(GL_ARRAY_BUFFER, env->buffer.vbo);
	glBufferData(GL_ARRAY_BUFFER, env->model.size_vertices,
		env->model.vertices, mode);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->buffer.ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, env->model.size_indices,
		env->model.indices, mode);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
		(GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
		(GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	create_texture(env);
}
