/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:08:27 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 19:13:06 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(int argc, char **argv)
{
	t_scop	scop;

	init(&scop, argc, argv);
	load_obj(&scop, scop.model.filename);
	load_bmp(&scop, "./resources/chaton.bmp");
	build_shader_program(&scop);
	buffering(&scop, GL_DYNAMIC_DRAW);
	glBindVertexArray(0);
	glEnable(GL_DEPTH_TEST);
	cicle(scop);
	free_glfw(&scop);
	return (0);
}
