/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:23:49 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/08 17:22:34 by wwatkins         ###   ########.fr       */
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

/*	Camera zoom */
# define ZP GLFW_KEY_KP_ADD
# define ZM GLFW_KEY_KP_SUBTRACT
/*	Camera movement */
# define CF GLFW_KEY_W
# define CB GLFW_KEY_S
# define CL GLFW_KEY_A
# define CR GLFW_KEY_D
# define CU GLFW_KEY_LEFT_SHIFT
# define CD GLFW_KEY_LEFT_CONTROL
/*	Model movement */
# define TF GLFW_KEY_I
# define TB GLFW_KEY_K
# define TL GLFW_KEY_J
# define TR GLFW_KEY_L
# define TU GLFW_KEY_PAGE_UP
# define TD GLFW_KEY_PAGE_DOWN
/*	Modifiers */
# define MW GLFW_KEY_1
# define MS GLFW_KEY_2
# define MC GLFW_KEY_C
# define MF GLFW_KEY_R

# define MAX_KEYS 348

# define FREE 0
# define LOCKED 1

typedef struct	s_cam
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	target;
	t_vec3	up;
	t_vec3	right;
	t_vec3	front;
	float	fov;
	t_vec3	inertia;
}				t_cam;

typedef struct	s_key
{
	// short	code[MAX_KEYS];
	// short	cooldown[MAX_KEYS];
	short	code;
	short	cooldown;
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
	t_vec3			center_axis;
	t_vec3			inertia;
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
	GLuint	VAO;
	GLuint	VBO;
	GLuint	EBO;
}				t_buffer;

typedef struct	s_shader
{
	GLuint	program;
	GLint	mvploc;
	GLint	cmdloc;
	GLint	smdloc;
}				t_shader;

typedef struct	s_win
{
	GLFWwindow	*ptr;
	int			w;
	int			h;
	float		ratio;
}				t_win;

typedef struct	s_mod
{
	short	wireframe;
	short	focus;
	short	shading;
	short	color;
	short	texture;
}				t_mod;

typedef struct	s_env
{
	t_win		win;
	t_sim		sim;
	t_cam		cam;
	t_key		key[MAX_KEYS];
	t_mod		mod;
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
void			key_toggle(t_key *key, short *var, int v0, int v1);

// shader.c
const GLchar	*get_shader_source(char *filename);
GLuint			create_shader(char *filename, int shaderType);
GLuint			create_shader_program(GLuint shader_vertex, GLuint shader_fragment);
void			build_shader_program(t_env *env, char *v_file, char *f_file);

// buffer.c
void			create_buffers(t_env *env, int mode);

// parsing.c
void			parse_obj(t_env *env, char *filename);
GLfloat			*append_vertices(GLfloat *array, char *line, int *length);
GLuint			*append_indices(GLuint *array, char *line, int *length);
t_vec3			compute_center_axis(GLfloat	*vertices, int num_vertices);

// utils.c
void			clean_glfw(t_env *env);
int				array_len(void **tab);

// coordinate_system.c
void			set_projection_matrix(t_mat4 *m, float fov, float ratio, float near, float far);
void			compute_mvp_matrix(t_env *env);

// movement.c
void			translate(t_mat4 *m, t_vec3 v);
void			rotate(t_mat4 *m, t_vec3 v);
void			scale(t_mat4 *m, t_vec3 v);
void			model_move_inertia(t_env *env, float inertia);
void			model_move_demo(t_env *env);

// camera.c
void			camera_zoom(t_env *env);
void			camera_move_inertia(t_env *env, float inertia, int mode);
void			camera_recenter(t_env *env);
void			camera_look_at_target(t_env *env);


#endif
