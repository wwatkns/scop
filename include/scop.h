/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:23:49 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/30 14:09:06 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

// User librairies
# include <libft.h>

// External librairies
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// OpenGL librairies
# include <GLFW/glfw3.h>

# define OPENGL_VERSION "4.0"
# define ABS(x) (x < 0 ? -x : x)
# define PI 3.1415926

typedef struct	s_win
{
	GLFWwindow	*ptr;
	int			width;
	int			height;
}				t_win;

typedef struct	s_env
{
	t_win		win;
}				t_env;

// init.c
void	glfw_init_env(void);
void	glfw_init_win(t_env *e, int w, int h);

// callback.c
void	key_callback(GLFWwindow *window, int key, int sc, int action, int mode);

#endif
