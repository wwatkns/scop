/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:13:41 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/12 11:34:03 by wwatkins         ###   ########.fr       */
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

GLuint	*gluint_array_copy(GLuint *array, int length, int m)
{
	int		i;
	GLuint	*new;

	i = -1;
	new = (GLuint*)malloc(sizeof(GLuint) * length);
	while (++i < length - m)
		new[i] = array[i];
	free(array);
	array = new;
	return (new);
}

void	error(char *info)
{
	ft_putstr("Error: ");
	ft_putstr(info);
	ft_putstr("\n");
	exit(0);
}

void	display_help(void)
{
	ft_putstr("[Help]:\n");
	ft_putstr("  Usage:\n\t./scop [.obj filename]\n");
	ft_putstr("  Keys:\n");
	ft_putstr("\t'w, a, s, d, shift, ctrl' Camera movement.\n");
	ft_putstr("\t'i, j, k, l, pgup, pgdwn' Model movement.\n");
	ft_putstr("\t'1' Wireframe modifier.\n");
	ft_putstr("\t'2' Shading modifier.\n");
	ft_putstr("\t'3' Greyscale modifier.\n");
	ft_putstr("\t'4' Texture projection modifier.\n");
	ft_putstr("\t't' Texture.\n");
	ft_putstr("\t'c' Color.\n");
	ft_putstr("\t'r' Camera anchor.\n");
	ft_putstr("\t'=, -' Faster/slower model rotation.\n");
	ft_putstr("\t'kp +, kp -' Augment/reduce camera FOV.\n\n");
	exit(0);
}
