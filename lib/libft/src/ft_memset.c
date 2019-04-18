/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:10:11 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/21 13:10:13 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	char *my_memptr;

	my_memptr = (void*)memptr;
	while (num)
	{
		*my_memptr = val;
		num--;
		my_memptr++;
	}
	return ((void*)memptr);
}
