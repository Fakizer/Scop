/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:00:15 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/03/28 14:25:00 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		parse(char *filename)
{
	char		*scene;
	int			fd;
	int			ret;

	fd = open(filename, O_RDONLY);
	while ((ret = get_next_line(fd, &scene)) > 0)
	{
		
		free(scene);
	}
}

int 		main(int ac, char **av)
{
	parse(av[1]);
	return (0);
}