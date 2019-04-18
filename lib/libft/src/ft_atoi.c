/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:34:50 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/23 13:34:51 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	char	*my_str;
	int		sum;
	int		min;

	my_str = (char*)str;
	sum = 0;
	min = 0;
	while ((*my_str > 8 && *my_str < 14) || *my_str == 32)
		my_str++;
	if (*my_str == '-')
		min = -1;
	if (*my_str == '+' || *my_str == '-')
		my_str++;
	while (*my_str > 47 && *my_str < 58)
	{
		if (min == -1)
			sum = sum * 10 - (*my_str - 48);
		else
			sum = sum * 10 + (*my_str - 48);
		my_str++;
	}
	return (sum);
}
