/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:23:49 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/07 15:41:37 by wwatkins         ###   ########.fr       */
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
# define BUFFER_SIZE 128
# define DEG2RAD(x) (x * (180.0 / PI))
# define RAD2DEG(x) (x * (PI / 180.0))

# define WINDOW_W 1440
# define WINDOW_H 1280
# define CAMERA_FOV 90

# define ZP GLFW_KEY_KP_ADD
# define ZM GLFW_KEY_KP_SUBTRACT
# define TF GLFW_KEY_W
# define TB GLFW_KEY_S
# define TL GLFW_KEY_A
# define TR GLFW_KEY_D
# define TU GLFW_KEY_LEFT_SHIFT
# define TD GLFW_KEY_LEFT_CONTROL

# define MAX_KEYS 348

# define FREE 0
# define LOCKED 1

typedef struct	s_cam
{
	t_vec4	pos;
	t_vec4	dir;
	t_vec4	target;
	t_vec4	up;
	t_vec4	right;
	t_vec4	front;
	float	fov;
	t_vec4	inertia;
}				t_cam;

typedef struct	s_key
{
	short	code[MAX_KEYS];
}				t_key;

typedef struct	s_model
{
	t_mat4			translation;
	t_mat4			scale;
	t_mat4			rotation;
	GLfloat			*vertices;
	GLuint			*indices;
	unsigned int	size_indices;
	unsigned int	size_vertices;
	unsigned int	num_indices;
	t_vec4			center_axis;
}				t_model;

typedef struct	s_sim
{
	t_mat4	model;
	t_mat4	view;
	t_mat4	projection;
	t_mat4	mvp;
}				t_sim;

typedef struct	s_buffer
{
	GLuint	VAO; //   Vertex array object.
	GLuint	VBO; //  Vertex buffer object.
	GLuint	EBO; // Element buffer object.
}				t_buffer;

typedef struct	s_shader
{
	GLuint	program;
	GLint	mvploc;
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
	t_buffer	buffer;
	t_shader	shader;
	t_model		model;
}				t_env;

// init.c
void			init_glfw_env(void);
void			init_glfw_win(t_env *env);
void			init_matrices(t_env *env);
void			init_cam(t_env *env);
void			init(t_env *env);

// callback.c
void			key_handle(t_env *env);
void			key_action(t_env *env);

// shader.c
const GLchar	*get_shader_source(char *filename);
GLuint			create_shader(char *filename, int shaderType);
GLuint			create_shader_program(GLuint shader_vertex, GLuint shader_fragment);
void			build_shader_program(t_env *env, char *v_file, char *f_file);

// buffer.c
void			create_buffers(t_env *env, int mode);

// parsing.c
void			parse_model(t_env *env);
void			parse_obj(t_env *env, char *filename);
GLfloat			*append_vertices(GLfloat *array, char *line, int *length);
GLuint			*append_indices(GLuint *array, char *line, int *length);

// utils.c
void			clean_glfw(t_env *env);

// coordinate_system.c
void			set_model_matrix(t_mat4 *m);
void			set_view_matrix(t_mat4 *m);
void			set_projection_matrix(t_mat4 *m, float fov, float ratio, float near, float far);
void			compute_mvp_matrix(t_env *env);

// movement.c
void			translate(t_mat4 *m, t_vec3 v);
void			rotate(t_mat4 *m, t_vec3 v);
void			scale(t_mat4 *m, t_vec3 v);

// camera.c
void			camera_zoom(t_env *env);
void			camera_move(t_env *env, int mode);
void			camera_move_inertia(t_env *env, float inertia, int mode);
void			camera_rotate(t_env *env);
void			camera_look_at_target(t_env *env);


#endif
