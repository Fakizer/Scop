/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:29:27 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/23 13:29:28 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while ((*str1 || *str2) && n)
	{
		if (*str1 != *str2)
			return (*(unsigned char*)str1 - *(unsigned char*)str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
