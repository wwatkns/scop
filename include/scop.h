/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:23:49 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/12 11:34:21 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/*
** User librairies
*/
# include "libft.h"
# include "libmat4.h"

/*
** External librairies
*/
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <GLFW/glfw3.h>

/*
** Modification line 146 in GLFW/glfw3.h: OpenGL/gl.h -> OpenGL/gl3.h
*/

# define OPENGL_VERSION "4.0"
# define BUFFER_SIZE 128
# define COOLDOWN 20
# define WINDOW_W 1440
# define WINDOW_H 1280
# define CAMERA_FOV 90
# define CAMERA_NEAR 0.001
# define CAMERA_FAR 100.0

/*
** Camera zoom
*/
# define ZP GLFW_KEY_KP_ADD
# define ZM GLFW_KEY_KP_SUBTRACT

/*
** Camera movement
*/
# define CF GLFW_KEY_W
# define CB GLFW_KEY_S
# define CL GLFW_KEY_A
# define CR GLFW_KEY_D
# define CU GLFW_KEY_LEFT_SHIFT
# define CD GLFW_KEY_LEFT_CONTROL

/*
** Model movement
*/
# define TF GLFW_KEY_I
# define TB GLFW_KEY_K
# define TL GLFW_KEY_J
# define TR GLFW_KEY_L
# define TU GLFW_KEY_PAGE_UP
# define TD GLFW_KEY_PAGE_DOWN
# define RM GLFW_KEY_MINUS
# define RP GLFW_KEY_EQUAL

/*
** Modifiers
*/
# define MW GLFW_KEY_1
# define MS GLFW_KEY_2
# define MG GLFW_KEY_3
# define MM GLFW_KEY_4
# define MC GLFW_KEY_C
# define MF GLFW_KEY_R
# define MT GLFW_KEY_T

# define MAX_KEYS 348

# define FREE 0
# define LOCKED 1

typedef struct	s_texture
{
	unsigned char	*img;
	int				size;
	int				w;
	int				h;
	int				sl;
	short			bpp;
	short			opp;
}				t_texture;

typedef struct	s_cam
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	target;
	t_vec3	up;
	t_vec3	right;
	t_vec3	front;
	t_vec3	inertia;
	float	fov;
	float	velocity;
}				t_cam;

typedef struct	s_key
{
	short	code;
	short	cooldown;
}				t_key;

typedef struct	s_model
{
	t_mat4			translation;
	t_mat4			rotation;
	GLfloat			*vertices;
	GLuint			*indices;
	unsigned int	size_indices;
	unsigned int	size_vertices;
	unsigned int	num_indices;
	t_vec3			center_axis;
	t_vec3			inertia;
	t_texture		texture;
	float			velocity;
	char			*filename;
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
	GLuint	vao;
	GLuint	vbo;
	GLuint	ebo;
	GLuint	texture;
}				t_buffer;

typedef struct	s_shader
{
	GLuint	program;
	GLint	mvploc;
	GLint	cmdloc;
	GLint	smdloc;
	GLint	tmdloc;
	GLint	gmdloc;
	GLint	mmdloc;
	GLint	texloc;
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
	short	greyscale;
	short	mapping;
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

/*
** init.c
*/
void			init_glfw_env(void);
void			init_glfw_win(t_env *env);
void			init_matrices(t_env *env);
void			init_cam(t_env *env);
void			init(t_env *env, int argc, char **argv);

/*
** callback.c
*/
void			key_handle(t_env *env);
void			key_action(t_env *env);
void			key_toggle(t_key *key, short *var, int v0, int v1);

/*
** shader.c
*/
void			update_shader_uniforms(t_env *env);
const GLchar	*get_shader_source(char *filename);
GLuint			create_shader(char *filename, int shader_type);
GLuint			create_shader_program(GLuint shader_vert, GLuint shader_frag);
void			build_shader_program(t_env *env);

/*
** buffer.c
*/
void			create_texture(t_env *env);
void			create_buffers(t_env *env, int mode);

/*
** parsing.c
*/
void			load_obj(t_env *env, char *filename);
GLfloat			*append_vertices(GLfloat *array, char *line, int *length);
GLuint			*append_indices(GLuint *array, char *line, int *length);
t_vec3			compute_center_axis(GLfloat	*vertices, int num_vertices);
void			center_vertices(t_env *env, int length);

/*
** texture.c
*/
void			load_bmp(t_env *env, char *filename);
void			get_image(t_texture *texture, char *buffer, int i);
void			read_header(char *filename, t_texture *texture);

/*
** utils.c
*/
void			clean_glfw(t_env *env);
int				array_len(void **tab);
GLuint			*gluint_array_copy(GLuint *array, int length, int m);
void			error(char *info);
void			display_help(void);

/*
** coordinate_system.c
*/
void			set_projection_matrix(t_env *env, float fov);
void			compute_mvp_matrix(t_env *env);

/*
** movement.c
*/
void			translate(t_mat4 *m, t_vec3 v);
void			rotate(t_mat4 *m, t_vec3 v);
void			model_move_inertia(t_env *env, float inertia);
void			model_move_demo(t_env *env);

/*
** camera.c
*/
void			camera_zoom(t_env *env);
void			camera_move_inertia(t_env *env, float inertia, int mode);
void			camera_center(t_env *env);
void			camera_look_at_target(t_env *env);

#endif
