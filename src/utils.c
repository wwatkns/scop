/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:13:41 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 12:15:23 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*	Properly delete the allocated buffers and all the
	resources allocated by glfw.
*/
void	clean_glfw(t_env *env)
{
	glDeleteVertexArrays(1, &env->buffer.VAO);
	glDeleteBuffers(1, &env->buffer.VBO);
	glDeleteBuffers(1, &env->buffer.EBO);
	glfwTerminate();
}
