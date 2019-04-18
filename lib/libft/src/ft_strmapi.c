/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:56:18 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/24 15:56:18 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*d;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	d = ft_strnew(ft_strlen(s));
	if (d == NULL)
		return (0);
	ft_strcpy(d, s);
	while (s[i])
	{
		d[i] = (*f)(i, d[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
