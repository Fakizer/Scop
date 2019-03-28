/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:57:29 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/19 21:35:01 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*my_s;
	size_t	i;
	size_t	len;

	i = 0;
	my_s = (char*)s;
	len = ft_strlen(my_s);
	while (my_s[i] == ' ' || my_s[i] == '\n' || my_s[i] == '\t')
		i++;
	if (i != len && (my_s[len - 1] == ' ' || my_s[len - 1] == '\n' ||
		my_s[len - 1] == '\t'))
	{
		len--;
		while (my_s[len] == ' ' || my_s[len] == '\n' || my_s[len] == '\t')
			len--;
	}
	str = ft_strnew(len - i + 1);
	if (str == NULL)
		return (0);
	ft_strncat(str, &my_s[i], len - i + 1);
	return (str);
}
