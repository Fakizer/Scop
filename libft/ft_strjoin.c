/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:57:15 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/24 15:57:16 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str1;
	char	*str2;
	size_t	len;

	str1 = (char*)s1;
	str2 = (char*)s2;
	len = ft_strlen(str1) + ft_strlen(str2);
	str = ft_strnew(len);
	if (str == NULL)
		return (0);
	ft_strcat(str, str1);
	ft_strcat(str, str2);
	return (str);
}
