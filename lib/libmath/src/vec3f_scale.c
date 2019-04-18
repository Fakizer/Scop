/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:21:50 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 15:40:49 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vec3f			vec3f_scale(t_vec3f v, float f)
{
	int			i;

	vec3f_normalize(v);
	i = -1;
	while (++i < 3)
		v.vec3f[i] *= f;
	return (v);
}
