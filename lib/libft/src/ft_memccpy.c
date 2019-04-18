/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:00:54 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/24 11:00:55 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	char *my_dest;
	char *my_src;

	my_src = (void*)src;
	my_dest = dest;
	while (num)
	{
		if ((*my_dest++ = *my_src++) == (char)c)
			return (my_dest);
		num--;
	}
	return (0);
}
