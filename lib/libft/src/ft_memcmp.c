/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:01:37 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/24 11:01:39 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *mptr1, const void *mptr2, size_t num)
{
	unsigned char *my_memptr1;
	unsigned char *my_memptr2;

	my_memptr1 = (void*)mptr1;
	my_memptr2 = (void*)mptr2;
	if (my_memptr1 == my_memptr2)
		return (0);
	while (num)
	{
		if (*my_memptr1 != *my_memptr2)
			return (*my_memptr1 - *my_memptr2);
		my_memptr1++;
		my_memptr2++;
		num--;
	}
	return (0);
}
