/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4f_transpose.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:29:23 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 16:46:03 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat4f		mat4f_transpose(t_mat4f m)
{
	int		h;
	int		w;
	t_mat4f	t;

	h = -1;
	while (++h < 4)
	{
		w = -1;
		while (++w < 4)
			t.mat4f[w * 4 + h] = m.mat4f[h * 4 + w];
	}
	m = mat4f_copy(&m, t);
	return (m);
}
