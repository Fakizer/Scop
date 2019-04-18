/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:44:28 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/22 14:44:30 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symb)
{
	size_t i;

	if (ft_strchr(str, symb))
	{
		i = ft_strlen(str);
		while (str[i] != symb)
			i--;
		return ((char*)str + i);
	}
	else
		return (0);
}
