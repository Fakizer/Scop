/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4f_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:28:33 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 15:45:19 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat4f		mat4f_add(t_mat4f a, t_mat4f b)
{
	int		i;

	i = -1;
	while (++i < 16)
		a.mat4f[i] += b.mat4f[i];
	return (a);
}
