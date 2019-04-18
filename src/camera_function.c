/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:17:39 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 19:40:02 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	camera_zoom(t_scop *scop)
{
	if (scop->key[ZP].code)
		set_projection_matrix(scop, scop->cam.fov -= 1);
	if (scop->key[ZM].code)
		set_projection_matrix(scop, scop->cam.fov += 1);
}

void	camera_move_inertia(t_scop *s, float inertia, int mode)
{
	t_vec3f	tmp;

	s->cam.inertia = vec3f_float_mult(s->cam.inertia, inertia);
	vec3f_copy(&tmp, &s->cam.pos);
	if (s->key[CF].code)
		s->cam.inertia = vec3f_sub(s->cam.inertia,
		vec3f_float_mult(s->cam.front, s->cam.velocity));
	if (s->key[CB].code)
		s->cam.inertia = vec3f_add(s->cam.inertia,
		vec3f_float_mult(s->cam.front, s->cam.velocity));
	if (s->key[CL].code)
		s->cam.inertia = vec3f_sub(s->cam.inertia,
		vec3f_float_mult(s->cam.right, s->cam.velocity));
	if (s->key[CR].code)
		s->cam.inertia = vec3f_add(s->cam.inertia,
		vec3f_float_mult(s->cam.right, s->cam.velocity));
	if (s->key[CU].code)
		s->cam.inertia = vec3f_add(s->cam.inertia,
		vec3f_float_mult(s->cam.up, s->cam.velocity));
	if (s->key[CD].code)
		s->cam.inertia = vec3f_sub(s->cam.inertia,
		vec3f_float_mult(s->cam.up, s->cam.velocity));
	s->cam.pos = vec3f_add(s->cam.pos, s->cam.inertia);
	if (mode == FREE)
		s->cam.target = vec3f_add(s->cam.target, vec3f_sub(s->cam.pos, tmp));
}

void	camera_center(t_scop *scop)
{
	t_vec3f	position;

	position.vec3f[0] = scop->model.translation.mat4f[3];
	position.vec3f[1] = scop->model.translation.mat4f[7];
	position.vec3f[2] = scop->model.translation.mat4f[11];
	scop->cam.target = vec3f_add(scop->model.center_axis, position);
}

void	camera_look_at_target(t_scop *scop)
{
	t_vec3f	tmp;
	t_mat4f	screen;

	tmp = scop->cam.up;
	scop->cam.front = vec3f_normalize(vec3f_sub(scop->cam.pos,
		scop->cam.target));
	scop->cam.right = vec3f_normalize(vec3f_cross(scop->cam.up,
		scop->cam.front));
	tmp = vec3f_cross(scop->cam.front, scop->cam.right);
	mat4f_setter(&screen, IDENTITY);
	screen.mat4f[0] = scop->cam.right.vec3f[0];
	screen.mat4f[1] = tmp.vec3f[0];
	screen.mat4f[2] = scop->cam.front.vec3f[0];
	screen.mat4f[4] = scop->cam.right.vec3f[1];
	screen.mat4f[5] = tmp.vec3f[1];
	screen.mat4f[6] = scop->cam.front.vec3f[1];
	screen.mat4f[8] = scop->cam.right.vec3f[2];
	screen.mat4f[9] = tmp.vec3f[2];
	screen.mat4f[10] = scop->cam.front.vec3f[2];
	screen.mat4f[12] = -vec3f_dot(scop->cam.right, scop->cam.pos);
	screen.mat4f[13] = -vec3f_dot(tmp, scop->cam.pos);
	screen.mat4f[14] = -vec3f_dot(scop->cam.front, scop->cam.pos);
	scop->sim.view = screen;
}
