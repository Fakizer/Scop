/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:22:27 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 18:33:09 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		set_projection_matrix(t_scop *scop, float fov)
{
	float	s;
	float	far;
	float	near;

	far = CAMERA_FAR;
	near = CAMERA_NEAR;
	s = 1 / (tan(fov * 0.5 * M_PI / 180.0));
	mat4f_setter(&scop->sim.projection, 0);
	scop->sim.projection.mat4f[0] = s / scop->win.ratio;
	scop->sim.projection.mat4f[5] = s;
	scop->sim.projection.mat4f[10] = -(far + near) / (far - near);
	scop->sim.projection.mat4f[11] = -1;
	scop->sim.projection.mat4f[14] = -2 * far * near / (far - near);
}

void		calc_mvp_matrix(t_scop *scop)
{
	scop->sim.mvp = mat4f_mult(mat4f_transpose(scop->sim.model),
		mat4f_mult(scop->sim.view, scop->sim.projection));
}
