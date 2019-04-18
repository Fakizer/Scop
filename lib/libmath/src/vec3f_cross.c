/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:19:29 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 16:45:01 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vec3f		vec3f_cross(t_vec3f a, t_vec3f b)
{
	t_vec3f	tmp;

	tmp.vec3f[0] = a.vec3f[1] * b.vec3f[2] - a.vec3f[2] * b.vec3f[1];
	tmp.vec3f[1] = a.vec3f[2] * b.vec3f[0] - a.vec3f[0] * b.vec3f[2];
	tmp.vec3f[2] = a.vec3f[0] * b.vec3f[1] - a.vec3f[1] * b.vec3f[0];
	vec3f_copy(&a, &tmp);
	return (a);
}
