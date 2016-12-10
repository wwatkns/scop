/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:53:07 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 12:14:34 by wwatkins         ###   ########.fr       */
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
	int		i;
	int		j;
	int		m;
	char	**tab;
	GLuint	*new;

	tab = ft_strsplit(&line[1], ' ');
	m = array_len((void**)tab) == 4 ? 6 : 3;
	*length += m;
	new = (GLuint*)malloc(sizeof(GLuint) * *length);
	i = -1;
	while (++i < *length - m)
		new[i] = array[i];
	free(array);
	array = new;
	j = -1;
	while (++j < 3)
	{
		array[*length - m + j] = (GLuint)ft_atoi(tab[j]) - 1;
		if (m == 6)
			array[*length - m + 3 + j] = (GLuint)ft_atoi(tab[j > 0 ? j + 1 : 0]) - 1;
		ft_strdel(&tab[j]);
	}
	ft_strdel(&tab[j]);
	free(tab);
	tab = NULL;
	return (array);
}

t_vec3	compute_center_axis(GLfloat	*vertices, int num_vertices)
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
		vertices[i] > max.x ? max.x = vertices[i] : 0;
		vertices[i] < min.x ? min.x = vertices[i] : 0;
		vertices[i + 1] > max.y ? max.y = vertices[i + 1] : 0;
		vertices[i + 1] < min.y ? min.y = vertices[i + 1] : 0;
		vertices[i + 2] > max.z ? max.z = vertices[i + 2] : 0;
		vertices[i + 2] < min.z ? min.z = vertices[i + 2] : 0;
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
		env->model.vertices[i] -= env->model.center_axis.x;
		env->model.vertices[i + 1] -= env->model.center_axis.y;
		env->model.vertices[i + 2] -= env->model.center_axis.z;
		tx = env->model.vertices[i] * cos(theta) -
			env->model.vertices[i + 2] * sin(theta);
		env->model.vertices[i + 2] = env->model.vertices[i] * sin(theta) +
			env->model.vertices[i + 2] * cos(theta);
		env->model.vertices[i] = tx;
		i += 6;
	}
}

void	load_obj(t_env *env, char *filename)
{
	int		fd;
	int		v;
	int		f;
	char	*line;

	v = 0;
	f = 0;
	env->model.vertices = (GLfloat*)malloc(sizeof(GLfloat) * 3);
	env->model.indices = (GLuint*)malloc(sizeof(GLuint) * 3);
	fd = open(filename, O_RDWR);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
			env->model.vertices = append_vertices(env->model.vertices, line, &v);
		else if (line[0] == 'f' && line[1] == ' ')
			env->model.indices = append_indices(env->model.indices, line, &f);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	env->model.size_vertices = v * sizeof(GLfloat);
	env->model.size_indices = f * sizeof(GLuint);
	env->model.num_indices = f;
	env->model.center_axis = compute_center_axis(env->model.vertices, v);
	center_vertices(env, v);
	env->model.center_axis = vec3(0, 0, 0);
}
