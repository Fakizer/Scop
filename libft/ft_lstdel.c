/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:09:12 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/27 17:09:13 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nlst;
	t_list *flst;

	flst = *alst;
	while (flst)
	{
		nlst = flst->next;
		(*del)(flst->content, flst->content_size);
		free(flst);
		flst = nlst;
	}
	*alst = NULL;
}
