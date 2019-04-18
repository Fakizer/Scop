/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:09:31 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/22 15:09:32 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	char *tmp1;
	char *tmp2;

	if (*str2 == '\0')
		return ((char*)str1);
	while (*str1)
	{
		tmp1 = (char*)str1;
		tmp2 = (char*)str2;
		while (*tmp2 == *tmp1 && *tmp2)
		{
			tmp1++;
			tmp2++;
		}
		if (*tmp2 == '\0')
			return ((char*)str1);
		str1++;
	}
	return (0);
}
