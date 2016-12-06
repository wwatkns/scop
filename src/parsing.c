/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:53:07 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 16:58:59 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	load_obj(char *filename)
{

}

void	load_mtl(char *filename)
{

}

void	parse_model(t_env *env)
{
	GLfloat	*vertices;
	GLfloat	*indices;

	env->model.size_vertices = sizeof(vertices); // to set after parsing
	env->model.size_indices = sizeof(indices);
}
