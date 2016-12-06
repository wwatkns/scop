/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:13:41 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 16:32:23 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	clean_glfw(t_env *env)
{
	glDeleteVertexArrays(1, &env->buffer.VAO);
	glDeleteBuffers(1, &env->buffer.VBO);
	glDeleteBuffers(1, &env->buffer.EBO);
	glfwTerminate();
}
