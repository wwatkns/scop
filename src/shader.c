/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:53:46 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 12:29:17 by wwatkins         ###   ########.fr       */
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

	source = (GLchar*)malloc(sizeof(GLchar) * BUFFER_SIZE + 1);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		source = ft_strjoin(source, buffer);
	}
	close(fd);
	return (source);
}

GLuint			create_shader(char *filename, int shader_type)
{
	GLint			success;
	GLchar			infoLog[512];
	GLuint			shader;
	const GLchar	*shader_source;

	shader_source = get_shader_source(filename);
	shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &shader_source, NULL);
	glCompileShader(shader);
	free((void*)shader_source);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		printf("ERROR: shader (%s) compilation failed:\n%s", filename, infoLog);
		exit(0);
	}
	return (shader);
}

GLuint			create_shader_program(GLuint shader_vertex, GLuint shader_fragment)
{
	GLint	success;
	GLchar	infoLog[512];
	GLuint	shader_program;

	shader_program = glCreateProgram();
	glAttachShader(shader_program, shader_vertex);
	glAttachShader(shader_program, shader_fragment);
	glLinkProgram(shader_program);
	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
		printf("ERROR: shader program compilation failed:\n%s", infoLog);
		exit(0);
	}
	glDeleteShader(shader_vertex);
	glDeleteShader(shader_fragment);
	return (shader_program);
}

void			build_shader_program(t_env *env, char *v_file, char *f_file)
{
	GLuint	shader_vertex;
	GLuint	shader_fragment;

	shader_vertex = create_shader(v_file, GL_VERTEX_SHADER);
	shader_fragment = create_shader(f_file, GL_FRAGMENT_SHADER);
	env->shader.program = create_shader_program(shader_vertex, shader_fragment);
	env->shader.mvploc = glGetUniformLocation(env->shader.program, "mvp");
	env->shader.smdloc = glGetUniformLocation(env->shader.program, "smod");
	env->shader.cmdloc = glGetUniformLocation(env->shader.program, "cmod");
	env->shader.tmdloc = glGetUniformLocation(env->shader.program, "tmod");
	env->shader.gmdloc = glGetUniformLocation(env->shader.program, "gmod");
	env->shader.mmdloc = glGetUniformLocation(env->shader.program, "mmod");
	env->shader.texloc = glGetUniformLocation(env->shader.program, "ltexture");
}
