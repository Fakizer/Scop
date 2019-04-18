/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:01:29 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 17:01:45 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double nb, int expo)
{
	double result;

	result = 1;
	while (expo > 0)
	{
		result = result * nb;
		expo--;
	}
	while (expo < 0)
	{
		result = result / nb;
		expo++;
	}
	return (result);
}
