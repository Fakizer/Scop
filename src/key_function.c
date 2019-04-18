/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:13:14 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 19:40:22 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_toggle(t_key *key, short *var, int v0, int v1)
{
	key->cooldown > 1 ? key->cooldown -= 1 : 0;
	if (key->code && key->cooldown <= 1)
	{
		if (*var == v1)
			*var = v0;
		else if (*var == v0)
			*var = v1;
		key->cooldown = COOLDOWN;
	}
}

void	key_action(t_scop *scop)
{
	if (scop->key[MW].code)
		glPolygonMode(GL_FRONT_AND_BACK, scop->mod.wireframe);
	if (scop->key[ZP].code || scop->key[ZM].code)
		camera_zoom(scop);
	if (scop->mod.focus)
		camera_center(scop);
	model_move_demo(scop);
	model_move_inertia(scop, 0.9);
	camera_move_inertia(scop, 0.93, FREE);
	camera_look_at_target(scop);
}

void	key_handle(t_scop *scop)
{
	int	i;

	if (glfwGetKey(scop->win.glwin, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(scop->win.glwin, GL_TRUE);
	i = -1;
	while (++i < MAX_KEYS)
		scop->key[i].code =
		glfwGetKey(scop->win.glwin, i) == GLFW_PRESS ? 1 : 0;
	key_toggle(&scop->key[MW], &scop->mod.wireframe, GL_FILL, GL_LINE);
	key_toggle(&scop->key[MF], &scop->mod.focus, 0, 1);
	key_toggle(&scop->key[MS], &scop->mod.shading, 0, 1);
	key_toggle(&scop->key[MC], &scop->mod.color, 0, 1);
	key_toggle(&scop->key[MG], &scop->mod.greyscale, 0, 1);
	key_toggle(&scop->key[MM], &scop->mod.mapping, 0, 1);
	key_toggle(&scop->key[MT], &scop->mod.texture, 0, 1);
	key_toggle(&scop->key[MQ], &scop->mod.animation, 0, 1);
	key_action(scop);
}
