/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:46:54 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/23 11:46:56 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return (*(unsigned char*)str1 - *(unsigned char*)str2);
		str1++;
		str2++;
	}
	return (0);
}
