/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:58:24 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/24 15:58:25 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_pos(char *str, int n, int len)
{
	str[--len] = '0' + (n % 10);
	n /= 10;
	while (n)
	{
		str[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (0);
	if (n >= 0)
		ft_pos(str, n, len);
	else
	{
		str[0] = '-';
		while (n)
		{
			str[--len] = '0' - (n % 10);
			n /= 10;
		}
	}
	return (str);
}
