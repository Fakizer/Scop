/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:21:36 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 15:42:26 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vec3f		vec3f_normalize(t_vec3f v)
{
	float	magnitude;

	magnitude = vec3f_magnitude(v);
	v.vec3f[0] /= magnitude;
	v.vec3f[1] /= magnitude;
	v.vec3f[2] /= magnitude;
	return (v);
}
