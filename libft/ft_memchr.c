/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:01:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/24 11:01:23 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memptr, int val, size_t num)
{
	char *my_memptr;

	my_memptr = (void*)memptr;
	if (num == 0)
		return (0);
	while (num)
	{
		if (*my_memptr == val)
			return (my_memptr);
		num--;
		my_memptr++;
	}
	return (0);
}
