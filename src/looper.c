/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:07:02 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 19:40:44 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	looper(void)
{
	glfwPollEvents();
	glClearColor(0.09f, 0.08f, 0.15f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void	cicle(t_scop scop)
{
	while (!glfwWindowShouldClose(scop.win.glwin))
	{
		looper();
		key_handle(&scop);
		if (scop.mod.animation == 1)
			scop.sim.model = mat4f_mult(scop.model.translation,
				scop.model.rotation);
		glUseProgram(scop.shader.program);
		calc_mvp_matrix(&scop);
		update_shaders(&scop);
		glBindTexture(GL_TEXTURE_2D, scop.buffer.texture);
		glBindVertexArray(scop.buffer.vao);
		glDrawElements(GL_TRIANGLES, scop.model.num_indices,
			GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(scop.win.glwin);
	}
}
