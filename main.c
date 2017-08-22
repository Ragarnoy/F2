/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:17:29 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/21 15:30:31 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	char	*str;
	int		i;

	str = ft_strnew(22);
	i = 0;
	if (argc != 2)
		return (0);
	if (ft_reader(ft_buffer(argv[1])))
	{
		ft_putstr("yes\n");
		return (1);
	}
	ft_putstr("no");
	return (0);
}
