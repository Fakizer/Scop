/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:08:49 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/27 17:08:50 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (0);
	if (content == NULL)
	{
		lst->content = NULL;
		content_size = 0;
	}
	else
	{
		lst->content = ft_strnew(content_size);
		if (lst->content == NULL)
			return (0);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
