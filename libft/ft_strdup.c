/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:40:07 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/21 14:40:09 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*istr;

	i = 0;
	len = ft_strlen(str);
	istr = (char *)malloc(sizeof(char) * (len + 1));
	if (istr == NULL)
		return (0);
	while (str[i] != '\0')
	{
		istr[i] = str[i];
		i++;
	}
	istr[i] = '\0';
	return (istr);
}
