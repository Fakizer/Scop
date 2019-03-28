/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:01:08 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/24 11:01:09 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t	i;
	char	*my_dest;
	char	*my_src;

	my_dest = (char*)dest;
	my_src = (char*)src;
	if (my_src > my_dest)
	{
		i = 0;
		while (i < num)
		{
			my_dest[i] = my_src[i];
			i++;
		}
	}
	else
	{
		i = num;
		while (i-- != 0)
			my_dest[i] = my_src[i];
	}
	return (dest);
}
