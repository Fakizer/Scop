/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:02:58 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 18:06:03 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_texture(t_scop *scop)
{
	glGenTextures(1, &scop->buffer.texture);
	glBindTexture(GL_TEXTURE_2D, scop->buffer.texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, scop->model.texture.w,
	scop->model.texture.h, 0, GL_RGB, GL_UNSIGNED_BYTE,
	scop->model.texture.img);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void	buffering(t_scop *scop, int mode)
{
	glGenBuffers(1, &scop->buffer.vbo);
	glGenBuffers(1, &scop->buffer.ebo);
	glGenVertexArrays(1, &scop->buffer.vao);
	glBindVertexArray(scop->buffer.vao);
	glBindBuffer(GL_ARRAY_BUFFER, scop->buffer.vbo);
	glBufferData(GL_ARRAY_BUFFER, scop->model.size_vertices,
		scop->model.vertices, mode);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scop->buffer.ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, scop->model.size_indices,
		scop->model.indices, mode);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
		(GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
		(GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	create_texture(scop);
}
