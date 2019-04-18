/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:24:56 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 19:21:56 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	rotate(t_mat4f *m, t_vec3f v)
{
	if (v.vec3f[0] != 0.0)
		*m = mat4f_axis_rotate(*m, AXIS_X, v.vec3f[0]);
	if (v.vec3f[1] != 0.0)
		*m = mat4f_axis_rotate(*m, AXIS_Y, v.vec3f[1]);
	if (v.vec3f[2] != 0.0)
		*m = mat4f_axis_rotate(*m, AXIS_Z, v.vec3f[2]);
}

void	model_move_demo(t_scop *scop)
{
	if (scop->key[RM].code)
		scop->model.velocity -= 0.05;
	if (scop->key[RP].code)
		scop->model.velocity += 0.05;
	rotate(&scop->model.rotation, new_vec3f(0, scop->model.velocity, 0));
}

void	translate(t_mat4f *m, t_vec3f v)
{
	m->mat4f[3] += v.vec3f[0];
	m->mat4f[7] += v.vec3f[1];
	m->mat4f[11] += v.vec3f[2];
}

void	model_move_inertia(t_scop *scop, float inertia)
{
	scop->model.inertia = vec3f_float_mult(scop->model.inertia, inertia);
	if (scop->key[TF].code)
		scop->model.inertia = vec3f_sub(scop->model.inertia,
		vec3f_float_mult(new_vec3f(scop->cam.front.vec3f[0], 0,
			scop->cam.front.vec3f[2]), 0.01));
	if (scop->key[TB].code)
		scop->model.inertia = vec3f_add(scop->model.inertia,
		vec3f_float_mult(new_vec3f(scop->cam.front.vec3f[0], 0,
			scop->cam.front.vec3f[2]), 0.01));
	if (scop->key[TL].code)
		scop->model.inertia = vec3f_sub(scop->model.inertia,
		vec3f_float_mult(scop->cam.right, 0.01));
	if (scop->key[TR].code)
		scop->model.inertia = vec3f_add(scop->model.inertia,
		vec3f_float_mult(scop->cam.right, 0.01));
	if (scop->key[TU].code)
		scop->model.inertia = vec3f_add(scop->model.inertia,
		vec3f_float_mult(scop->cam.up, 0.01));
	if (scop->key[TD].code)
		scop->model.inertia = vec3f_sub(scop->model.inertia,
		vec3f_float_mult(scop->cam.up, 0.01));
	translate(&scop->model.translation, scop->model.inertia);
}
