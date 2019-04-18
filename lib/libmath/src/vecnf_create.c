/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecnf_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:29:43 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 15:39:39 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vec3f		new_vec3f(float x, float y, float z)
{
	t_vec3f	new;

	new.vec3f[0] = x;
	new.vec3f[1] = y;
	new.vec3f[2] = z;
	return (new);
}

t_vec4f		new_vec4f(float x, float y, float z, float w)
{
	t_vec4f	new;

	new.vec4f[0] = x;
	new.vec4f[1] = y;
	new.vec4f[2] = z;
	new.vec4f[3] = w;
	return (new);
}
