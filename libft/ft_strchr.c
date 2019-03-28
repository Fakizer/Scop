/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:48:19 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/22 13:48:23 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int symb)
{
	char *dst;

	dst = (char*)str;
	while (*dst != symb && *dst)
	{
		dst++;
	}
	if (*dst == symb)
		return (dst);
	else
		return (0);
}
