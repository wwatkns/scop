/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:39:39 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/12 11:37:11 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	read_header(char *filename, t_texture *texture)
{
	FILE	*file;

	if ((file = fopen(filename, "r")) == NULL)
		error("bmp file opening (fopen) failed.");
	fseek(file, 18, SEEK_SET);
	fread(&texture->w, 4, 1, file);
	fread(&texture->h, 4, 1, file);
	fseek(file, 2, SEEK_CUR);
	fread(&texture->bpp, 2, 1, file);
	fclose(file);
	texture->opp = texture->bpp / 8;
	texture->sl = texture->w * texture->opp;
	texture->w < 0 ? texture->w = -texture->w : 0;
	texture->h < 0 ? texture->h = -texture->h : 0;
	texture->size = texture->sl * texture->h;
}

void	get_image(t_texture *texture, char *buffer, int i)
{
	int	h;
	int	j;
	int	size;

	h = 0;
	size = texture->size * 2;
	texture->img = (unsigned char*)malloc(sizeof(unsigned char) * size);
	while (i >= 0)
	{
		i -= texture->sl;
		j = 0;
		while (j < texture->sl)
		{
			texture->img[h + j] = (unsigned char)buffer[i + j + 2];
			texture->img[h + j + 1] = (unsigned char)buffer[i + j + 1];
			texture->img[h + j + 2] = (unsigned char)buffer[i + j];
			j += 3;
		}
		h += texture->sl;
	}
}

void	load_bmp(t_env *env, char *filename)
{
	int		fd;
	int		i;
	char	*buffer;

	read_header(filename, &env->model.texture);
	buffer = (char*)malloc(sizeof(char) * env->model.texture.size + 1);
	if ((fd = open(filename, O_RDWR)) == -1)
		error("bmp file opening failed.");
	lseek(fd, 54, SEEK_SET);
	i = read(fd, buffer, env->model.texture.size);
	get_image(&env->model.texture, buffer, i);
	ft_strdel((char**)&buffer);
	close(fd);
}
