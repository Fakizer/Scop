/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:22:20 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 14:23:51 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	vec3f_setter(t_vec3f *v, float f)
{
	int		i;

	i = -1;
	while (++i < 3)
		v->vec3f[i] = f;
}
