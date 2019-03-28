/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:13:24 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/22 16:13:25 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	if (*str2 == '\0')
		return ((char*)str1);
	while (*str1 && n)
	{
		tmp1 = (char*)str1;
		tmp2 = (char*)str2;
		i = n;
		while (*tmp2 == *tmp1 && *tmp2 && i)
		{
			tmp1++;
			tmp2++;
			i--;
		}
		if (*tmp2 == '\0')
			return ((char*)str1);
		str1++;
		n--;
	}
	return (0);
}
