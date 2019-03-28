/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:05:45 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/21 16:05:46 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	const char	*odest;
	const char	*osrc;
	size_t		n;
	size_t		dlen;

	n = size;
	odest = dest;
	osrc = src;
	while (n-- != 0 && *dest != '\0')
		dest++;
	dlen = dest - odest;
	n = size - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dest++ = *src;
			n--;
		}
		src++;
	}
	*dest = '\0';
	return (dlen + (src - osrc));
}
