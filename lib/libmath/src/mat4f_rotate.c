/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4f_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:28:57 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 14:30:38 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void		set_x_axis_rotation_mat4f(t_mat4f *m, float theta)
{
	m->mat4f[5] = cos(theta);
	m->mat4f[6] = sin(theta);
	m->mat4f[9] = -sin(theta);
	m->mat4f[10] = cos(theta);
}

void		set_y_axis_rotation_mat4f(t_mat4f *m, float theta)
{
	m->mat4f[0] = cos(theta);
	m->mat4f[2] = -sin(theta);
	m->mat4f[8] = sin(theta);
	m->mat4f[10] = cos(theta);
}

void		set_z_axis_rotation_mat4f(t_mat4f *m, float theta)
{
	m->mat4f[0] = cos(theta);
	m->mat4f[1] = sin(theta);
	m->mat4f[4] = -sin(theta);
	m->mat4f[5] = cos(theta);
}

t_mat4f		mat4f_axis_rotate(t_mat4f m, int axis, float angle)
{
	t_mat4f	r;
	float	theta;

	mat4f_setter(&r, IDENTITY);
	theta = angle * (M_PI / 180);
	if (axis == AXIS_X)
	{
		set_x_axis_rotation_mat4f(&r, theta);
		m = mat4f_mult(m, r);
	}
	else if (axis == AXIS_Y)
	{
		set_y_axis_rotation_mat4f(&r, theta);
		m = mat4f_mult(m, r);
	}
	else if (axis == AXIS_Z)
	{
		set_z_axis_rotation_mat4f(&r, theta);
		m = mat4f_mult(m, r);
	}
	return (m);
}
