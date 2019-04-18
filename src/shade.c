/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:56:03 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 19:41:14 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			update_shaders(t_scop *scop)
{
	glUniformMatrix4fv(scop->shader.mvploc, 1, GL_FALSE, scop->sim.mvp.mat4f);
	glUniform1i(scop->shader.smdloc, scop->mod.shading);
	glUniform1i(scop->shader.cmdloc, scop->mod.color);
	glUniform1i(scop->shader.gmdloc, scop->mod.greyscale);
	glUniform1i(scop->shader.mmdloc, scop->mod.mapping);
	glUniform1i(scop->shader.tmdloc, scop->mod.texture);
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

void			build_shader_program(t_scop *scop)
{
	GLuint	shader_vert;
	GLuint	shader_frag;

	shader_vert = create_shader("./shader/vertex.glsl", GL_VERTEX_SHADER);
	shader_frag = create_shader("./shader/fragment.glsl", GL_FRAGMENT_SHADER);
	scop->shader.program = create_shader_program(shader_vert, shader_frag);
	scop->shader.mvploc = glGetUniformLocation(scop->shader.program, "mvp");
	scop->shader.smdloc = glGetUniformLocation(scop->shader.program, "smod");
	scop->shader.cmdloc = glGetUniformLocation(scop->shader.program, "cmod");
	scop->shader.tmdloc = glGetUniformLocation(scop->shader.program, "tmod");
	scop->shader.gmdloc = glGetUniformLocation(scop->shader.program, "gmod");
	scop->shader.mmdloc = glGetUniformLocation(scop->shader.program, "mmod");
	scop->shader.texloc = glGetUniformLocation(scop->shader.program,
		"ltexture");
}
