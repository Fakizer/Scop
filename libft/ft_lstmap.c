/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:09:43 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/27 17:09:44 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *my_lst;
	t_list *start;

	if (lst == NULL)
		return (0);
	my_lst = (*f)(lst);
	start = my_lst;
	while (lst->next)
	{
		lst = lst->next;
		my_lst->next = (*f)(lst);
		my_lst = my_lst->next;
	}
	return (start);
}
