/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:53:07 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 19:29:29 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	print_debug_vertices(t_env *env)
{
	int j;

	j = -1;
	while (++j < env->model.size_vertices)
	{
		(j + 1) % 3 == 1 ? printf("( ") : 0;
		printf("%f ", env->model.vertices[j]);
		(j + 1) % 3 == 0 ? printf(")\n") : 0;
	}
}

void	print_debug_indices(t_env *env)
{
	int j;

	j = -1;
	while (++j < env->model.size_indices)
	{
		(j + 1) % 3 == 1 ? printf("( ") : 0;
		printf("%u ", env->model.indices[j]);
		(j + 1) % 3 == 0 ? printf(")\n") : 0;
	}
}

GLfloat	*append_vertices(GLfloat *array, char *line, int length)
{
	int		i;
	int		j;
	char	**tab;
	GLfloat	*new;

	tab = ft_strsplit(&line[1], ' ');
	new = (GLfloat*)malloc(sizeof(GLfloat) * length);
	i = -1;
	while (++i < length - 3)
		new[i] = array[i];
	free(array);
	array = new;
	j = -1;
	while (tab[++j] != NULL)
	{
		array[length - 3 + j] = (GLfloat)ft_atof(tab[j]);
		ft_strdel(&tab[j]);
	}
	free(tab);
	tab = NULL;
	return (new);
}

GLuint	*append_indices(GLuint *array, char *line, int length)
{
	int		i;
	int		j;
	char	**tab;
	GLuint	*new;

	tab = ft_strsplit(&line[1], ' ');
	new = (GLuint*)malloc(sizeof(GLuint) * length);
	i = -1;
	while (++i < length - 3)
		new[i] = array[i];
	free(array);
	array = new;
	j = -1;
	while (tab[++j] != NULL)
	{
		array[length - 3 + j] = (GLuint)ft_atoi(tab[j]);
		ft_strdel(&tab[j]);
	}
	free(tab);
	tab = NULL;
	return (new);
}

void	parse_obj(t_env *env, char *filename)
{
	int		fd;
	int		v;
	int		f;
	char	*line;

	v = 0;
	f = 0;
	fd = open(filename, O_RDWR);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			v++;
			env->model.vertices = append_vertices(env->model.vertices, line, v * 3);
		}
		else if (line[0] == 'f' && line[1] == ' ')
		{
			f++;
			env->model.indices = append_indices(env->model.indices, line, f * 3);
		}
	}
	env->model.size_vertices = v * 3 * 4; // nope because quads also exists.
	env->model.size_indices = f * 3 * 4; // nope because quads also exists.
	env->model.amount_indices = f * 3; // nope because quads also exists.
	// print_debug_vertices(env);
	// print_debug_indices(env);
	// printf("%d\n", env->model.size_vertices);
	// printf("%d\n", env->model.size_indices);
}

void	load_mtl(char *filename)
{

}

void	parse_model(t_env *env)
{
	parse_obj(env, "../resources/teapot.obj");
}
