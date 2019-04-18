/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:22:04 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 15:42:11 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void		rotate_x_axis(t_vec3f *b, t_vec3f v, t_vec3f a)
{
	b->vec3f[1] = v.vec3f[1] * cos(a.vec3f[0]) - v.vec3f[2] * sin(a.vec3f[0]);
	b->vec3f[2] = v.vec3f[1] * sin(a.vec3f[0]) + v.vec3f[2] * cos(a.vec3f[0]);
}

void		rotate_y_axis(t_vec3f *b, t_vec3f v, t_vec3f a)
{
	b->vec3f[0] = v.vec3f[0] * cos(a.vec3f[1]) - v.vec3f[2] * sin(a.vec3f[1]);
	b->vec3f[2] = v.vec3f[0] * sin(a.vec3f[1]) + v.vec3f[2] * cos(a.vec3f[1]);
}

void		rotate_z_axis(t_vec3f *b, t_vec3f v, t_vec3f a)
{
	b->vec3f[0] = v.vec3f[0] * cos(a.vec3f[2]) - v.vec3f[1] * sin(a.vec3f[2]);
	b->vec3f[1] = v.vec3f[0] * sin(a.vec3f[2]) + v.vec3f[1] * cos(a.vec3f[2]);
}

t_vec3f		vec3f_rotate(t_vec3f v, t_vec3f a)
{
	t_vec3f	b;

	vec3f_copy(&b, &v);
	if (a.vec3f[2] != 0.0)
	{
		a.vec3f[2] *= (M_PI / 180);
		rotate_z_axis(&b, v, a);
	}
	if (a.vec3f[1] != 0.0)
	{
		a.vec3f[1] *= (M_PI / 180);
		rotate_y_axis(&b, v, a);
	}
	if (a.vec3f[0] != 0.0)
	{
		a.vec3f[0] *= (M_PI / 180);
		rotate_x_axis(&b, v, a);
	}
	vec3f_copy(&v, &b);
	return (v);
}
