/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:17:29 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/30 11:57:06 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int argc, char *argv[])
{
	char		*str;
	int			i;
	t_tlist	*elem;

	str = ft_strnew(22);
	i = 0;
	if (argc != 2)
		return (0);
	if ((elem = ft_reader(ft_buffer(argv[1]))))
	{
		while(elem->next)
		{
			printf("ID= %d, L= %c\n",elem->id, elem->letter);
			elem = elem->next;
		}
		printf("ID= %d, L= %c\n",elem->id, elem->letter);
		ft_putstr("yes\n");
		return (1);
	}
	ft_putstr("no");
	return (0);
}
