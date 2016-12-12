/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:53:46 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/12 11:40:02 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			update_shader_uniforms(t_env *env)
{
	glUniformMatrix4fv(env->shader.mvploc, 1, GL_FALSE, env->sim.mvp.m);
	glUniform1i(env->shader.smdloc, env->mod.shading);
	glUniform1i(env->shader.cmdloc, env->mod.color);
	glUniform1i(env->shader.gmdloc, env->mod.greyscale);
	glUniform1i(env->shader.mmdloc, env->mod.mapping);
	glUniform1i(env->shader.tmdloc, env->mod.texture);
}

const GLchar	*get_shader_source(char *filename)
{
	int		fd;
	int		ret;
	char	buffer[BUFFER_SIZE];
	char	*source;
	char	*del;

	source = ft_strnew(BUFFER_SIZE);
	if ((fd = open(filename, O_RDONLY)) == -1)
		error("shader source file opening failed.");
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		del = source;
		source = ft_strjoin(source, buffer);
		ft_strdel(&del);
	}
	close(fd);
	return (source);
}

GLuint			create_shader(char *filename, int shader_type)
{
	GLint			success;
	GLuint			shader;
	const GLchar	*shader_source;

	shader_source = get_shader_source(filename);
	shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &shader_source, NULL);
	glCompileShader(shader);
	free((void*)shader_source);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
		error("shader compilation failed.");
	return (shader);
}

GLuint			create_shader_program(GLuint shader_vert, GLuint shader_frag)
{
	GLint	success;
	GLuint	shader_program;

	shader_program = glCreateProgram();
	glAttachShader(shader_program, shader_vert);
	glAttachShader(shader_program, shader_frag);
	glLinkProgram(shader_program);
	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if (!success)
		error("shader program compilation failed.");
	glDeleteShader(shader_vert);
	glDeleteShader(shader_frag);
	return (shader_program);
}

void			build_shader_program(t_env *env)
{
	GLuint	shader_vert;
	GLuint	shader_frag;

	shader_vert = create_shader("./shader/vertex.glsl", GL_VERTEX_SHADER);
	shader_frag = create_shader("./shader/fragment.glsl", GL_FRAGMENT_SHADER);
	env->shader.program = create_shader_program(shader_vert, shader_frag);
	env->shader.mvploc = glGetUniformLocation(env->shader.program, "mvp");
	env->shader.smdloc = glGetUniformLocation(env->shader.program, "smod");
	env->shader.cmdloc = glGetUniformLocation(env->shader.program, "cmod");
	env->shader.tmdloc = glGetUniformLocation(env->shader.program, "tmod");
	env->shader.gmdloc = glGetUniformLocation(env->shader.program, "gmod");
	env->shader.mmdloc = glGetUniformLocation(env->shader.program, "mmod");
	env->shader.texloc = glGetUniformLocation(env->shader.program, "ltexture");
}
