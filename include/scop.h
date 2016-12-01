/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:23:49 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 14:27:33 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

// User librairies
# include <libft.h>

// External librairies
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <GLFW/glfw3.h>
// Modification line 146 in GLFW/glfw3.h: OpenGL/gl.h -> OpenGL/gl3.h

# define OPENGL_VERSION "4.0"
# define ABS(x) (x < 0 ? -x : x)
# define PI 3.1415926
# define BUFFER_SIZE 128
# define DEG2RAD(x) (x * (180.0 / PI))
# define RAD2DEG(x) (x * (PI / 180.0))

typedef struct	s_data
{
	unsigned int	size_vertices;
	unsigned int	size_indices;
}				t_data;

typedef struct	s_buffer
{
	GLuint		VAO; //   Vertex array object.
	GLuint		VBO; //  Vertex buffer object.
	GLuint		EBO; // Element buffer object.
}				t_buffer;

typedef struct	s_shader
{
	GLuint	program;
}				t_shader;

typedef struct	s_win
{
	GLFWwindow	*ptr;
	int			width;
	int			height;
}				t_win;

typedef struct	s_env
{
	t_win		win;
	t_data		data;
	t_buffer	buffer;
	t_shader	shader;
}				t_env;

// init.c
void			init_glfw_env(void);
void			init_glfw_win(t_env *e, int w, int h);

// callback.c
void			key_callback(GLFWwindow *window, int key, int sc, int action, int mode);

// shader.c
const GLchar	*get_shader_source(char *filename);
GLuint			create_shader(char *filename, int shaderType);
GLuint			create_shader_program(GLuint shader_vertex, GLuint shader_fragment);
void			build_shader_program(t_env *env, char *v_file, char *f_file);

// buffer.c
void			create_buffers(t_env *env, GLfloat *vertices, GLuint *indices, int mode);

// utils.c
void	clean_glfw(t_env *env);


#endif
