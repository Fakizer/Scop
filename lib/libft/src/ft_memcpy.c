/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:00:42 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/24 11:00:43 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char *my_dest;
	char *my_src;

	my_src = (void*)src;
	my_dest = dest;
	while (num)
	{
		*my_dest = *my_src;
		my_src++;
		my_dest++;
		num--;
	}
	return ((void*)dest);
}
