/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:53:07 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/12 11:37:31 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLfloat	*append_vertices(GLfloat *array, char *line, int *length)
{
	int		i;
	int		j;
	char	**tab;
	GLfloat	*new;

	tab = ft_strsplit(&line[1], ' ');
	*length += 6;
	new = (GLfloat*)malloc(sizeof(GLfloat) * *length);
	i = -1;
	while (++i < *length - 6)
		new[i] = array[i];
	free(array);
	array = new;
	j = -1;
	while (tab[++j] != NULL)
	{
		array[*length - 6 + j] = (GLfloat)ft_atof(tab[j]);
		array[*length - 3 + j] = j * 0.66f;
		ft_strdel(&tab[j]);
	}
	ft_strdel(&tab[j]);
	free(tab);
	tab = NULL;
	return (array);
}

GLuint	*append_indices(GLuint *array, char *line, int *length)
{
	int		j;
	int		m;
	char	**tab;

	tab = ft_strsplit(&line[1], ' ');
	m = array_len((void**)tab) == 4 ? 6 : 3;
	*length += m;
	array = gluint_array_copy(array, *length, m);
	j = -1;
	while (++j < 3)
	{
		array[*length - m + j] = (GLuint)ft_atoi(tab[j]) - 1;
		if (m == 6)
			array[*length - m + 3 + j] =
			(GLuint)ft_atoi(tab[j > 0 ? j + 1 : 0]) - 1;
		ft_strdel(&tab[j]);
	}
	ft_strdel(&tab[j]);
	free(tab);
	tab = NULL;
	return (array);
}

t_vec3	compute_center_axis(GLfloat *vertices, int num_vertices)
{
	int		i;
	t_vec3	max;
	t_vec3	min;
	t_vec3	center;

	i = 0;
	max = vec3(0, 0, 0);
	min = vec3(0, 0, 0);
	while (i < num_vertices - 6)
	{
		vertices[i] > max.v[0] ? max.v[0] = vertices[i] : 0;
		vertices[i] < min.v[0] ? min.v[0] = vertices[i] : 0;
		vertices[i + 1] > max.v[1] ? max.v[1] = vertices[i + 1] : 0;
		vertices[i + 1] < min.v[1] ? min.v[1] = vertices[i + 1] : 0;
		vertices[i + 2] > max.v[2] ? max.v[2] = vertices[i + 2] : 0;
		vertices[i + 2] < min.v[2] ? min.v[2] = vertices[i + 2] : 0;
		i += 6;
	}
	center = vec3_fmul(vec3_add(max, min), 0.5);
	return (center);
}

void	center_vertices(t_env *env, int length)
{
	int		i;
	float	tx;
	float	theta;

	i = 0;
	theta = 90 * (M_PI / 180);
	while (i < length)
	{
		env->model.vertices[i] -= env->model.center_axis.v[0];
		env->model.vertices[i + 1] -= env->model.center_axis.v[1];
		env->model.vertices[i + 2] -= env->model.center_axis.v[2];
		tx = env->model.vertices[i] * cos(theta) -
			env->model.vertices[i + 2] * sin(theta);
		env->model.vertices[i + 2] = env->model.vertices[i] * sin(theta) +
			env->model.vertices[i + 2] * cos(theta);
		env->model.vertices[i] = tx;
		i += 6;
	}
	env->model.center_axis = vec3(0, 0, 0);
}

void	load_obj(t_env *e, char *filename)
{
	int		fd;
	int		v;
	int		f;
	char	*line;

	v = 0;
	f = 0;
	e->model.vertices = (GLfloat*)malloc(sizeof(GLfloat) * 3);
	e->model.indices = (GLuint*)malloc(sizeof(GLuint) * 3);
	if ((fd = open(filename, O_RDWR)) == -1)
		error("obj file opening failed.");
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
			e->model.vertices = append_vertices(e->model.vertices, line, &v);
		else if (line[0] == 'f' && line[1] == ' ')
			e->model.indices = append_indices(e->model.indices, line, &f);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	e->model.size_vertices = v * sizeof(GLfloat);
	e->model.size_indices = f * sizeof(GLuint);
	e->model.num_indices = f;
	e->model.center_axis = compute_center_axis(e->model.vertices, v);
	center_vertices(e, v);
}
