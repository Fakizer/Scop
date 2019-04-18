/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4f_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:28:49 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 15:44:43 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat4f		mat4f_mult(t_mat4f a, t_mat4f b)
{
	int		h;
	int		w;
	int		z;
	t_mat4f m;

	h = -1;
	while (++h < 4)
	{
		w = -1;
		while (++w < 4)
		{
			z = -1;
			m.mat4f[h * 4 + w] = 0;
			while (++z < 4)
				m.mat4f[h * 4 + w] += a.mat4f[h * 4 + z] * b.mat4f[z * 4 + w];
		}
	}
	return (m);
}
