/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:53:46 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 16:32:14 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

const GLchar	*get_shader_source(char *filename)
{
	int		fd;
	int		ret;
	char	buffer[BUFFER_SIZE];
	char	*source;

	source = (GLchar*)malloc(sizeof(GLchar) * BUFFER_SIZE + 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		source = ft_strjoin(source, buffer);
	}
	close(fd);
	return (source);
}

GLuint	create_shader(char *filename, int shaderType)
{
	GLint			success;
	GLchar			infoLog[512];
	GLuint			shader;
	const GLchar	*shaderSource;

	shaderSource = get_shader_source(filename);
	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		printf("ERROR: shader (%s) compilation failed:\n%s", filename, infoLog);
		exit(0);
	}
	return (shader);
}

GLuint	create_shader_program(GLuint shader_vertex, GLuint shader_fragment)
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

void	build_shader_program(t_env *env, char *v_file, char *f_file)
{
	GLuint	shader_vertex;
	GLuint	shader_fragment;

	shader_vertex = create_shader(v_file, GL_VERTEX_SHADER);
	shader_fragment = create_shader(f_file, GL_FRAGMENT_SHADER);
	env->shader.program = create_shader_program(shader_vertex, shader_fragment);
	env->shader.mloc = glGetUniformLocation(env->shader.program, "model");
	env->shader.vloc = glGetUniformLocation(env->shader.program, "view");
	env->shader.ploc = glGetUniformLocation(env->shader.program, "projection");
}
