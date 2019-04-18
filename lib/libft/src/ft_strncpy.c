/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:45:27 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/21 15:45:28 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	size_t i;

	i = 0;
	while (num)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
		{
			while (num)
			{
				dest[i] = '\0';
				i++;
				num--;
			}
			break ;
		}
		i++;
		num--;
	}
	return (dest);
}
