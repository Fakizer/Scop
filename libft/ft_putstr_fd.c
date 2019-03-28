/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:00:18 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/24 16:00:19 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)s;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
