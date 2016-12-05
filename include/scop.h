/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:23:49 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/05 19:19:38 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

// User librairies
# include "libft.h"
# include "libmat4.h"

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

# define WINDOW_W 1440
# define WINDOW_H 1280

typedef struct	s_cam
{
	t_vec4	pos;
	t_vec4	dir;
	t_vec4	target;
	t_vec4	up;
	t_vec4	right;
	float	fov;
}				t_cam;

typedef struct	s_key
{
	short	code[512];
}				t_key;

/*	Model matrices for the following operations:
**	translation, scale, rotation.
*/
typedef struct	s_model
{
	t_mat4	translation;
	t_mat4	scale;
	t_mat4	rotation;
}				t_model;

/*	Simulation matrices (model, view, projection).
*/
typedef struct	s_sim
{
	t_mat4	model;
	t_mat4	view;
	t_mat4	projection;
}				t_sim;

typedef struct	s_data
{
	unsigned int	size_vertices;
	unsigned int	size_indices;
}				t_data;

typedef struct	s_buffer
{
	GLuint	VAO; //   Vertex array object.
	GLuint	VBO; //  Vertex buffer object.
	GLuint	EBO; // Element buffer object.
}				t_buffer;

typedef struct	s_shader
{
	GLuint	program;
	GLint	mloc;
	GLint	vloc;
	GLint	ploc;
}				t_shader;

typedef struct	s_win
{
	GLFWwindow	*ptr;
	int			w;
	int			h;
	float		ratio;
}				t_win;

typedef struct	s_env
{
	t_win		win;
	t_sim		sim;
	t_cam		cam;
	t_key		key;
	t_data		data;
	t_buffer	buffer;
	t_shader	shader;
	t_model		model;
}				t_env;

// init.c
void			init_glfw_env(void);
void			init_glfw_win(t_env *env);
void			init_cam(t_env *env);
void			init(t_env *env);

// callback.c
// void			key_callback(GLFWwindow *window, int key, int sc, int action, int mode);
void			key_reset(t_env *env);
void			key_pressed(t_env *env);

// shader.c
const GLchar	*get_shader_source(char *filename);
GLuint			create_shader(char *filename, int shaderType);
GLuint			create_shader_program(GLuint shader_vertex, GLuint shader_fragment);
void			build_shader_program(t_env *env, char *v_file, char *f_file);

// buffer.c
void			create_buffers(t_env *env, GLfloat *vertices, GLuint *indices, int mode);

// utils.c
void			clean_glfw(t_env *env);

// coordinate_system.c
void			set_model_matrix(t_mat4 *m);
void			set_view_matrix(t_mat4 *m);
void			set_projection_matrix(t_mat4 *m, float fov, float ratio, float near, float far);

// movement.c
void			translate(t_mat4 *m, t_vec3 v);
// void			rotate(t_mat4 *m, float theta, t_vec3 v);
void			rotate(t_mat4 *m, t_vec3 v);
void			scale(t_mat4 *m, t_vec3 v);

t_mat4			look_at(t_vec4 *from, t_vec4 *to);

#endif
