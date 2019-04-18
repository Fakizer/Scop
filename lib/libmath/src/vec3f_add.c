/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:18:25 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 14:23:27 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vec3f	vec3f_add(t_vec3f a, t_vec3f b)
{
	int	i;

	i = -1;
	while (++i < 3)
		a.vec3f[i] += b.vec3f[i];
	return (a);
}