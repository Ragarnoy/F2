/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:17:29 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/06 14:18:29 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_buffer(char *pth)
{
	int fd;
	int end;
	char *buf;
	char *tmp;

	if ((fd = open(pth, O_RDONLY)) == -1 || !(buf = ft_strnew(BUFFMAX_I)))
		return (0);
	while ((end = read(fd, buf, BUFFMAX_I)) > 0)
		buf[end] = '\0';
	if ((close(fd)) == -1)
		return (0);
	tmp = ft_strsub(buf, 0, ft_strlen(buf));
	free(buf);
	return (tmp);
}

int			main(int argc, char *argv[])
{
	char		*str;
	int			i;
	t_tlist		*elem;

	str = ft_strnew(22);
	i = 0;
	if (argc != 2)
		return (0);
	if ((elem = ft_reader(ft_buffer(argv[1]))))
	{
		while(elem)
		{
			printf("\n%s\nLetter= %c\n",elem->tetri, elem->letter);
			elem = elem->next;
		}
		ft_putstr("yes\n");
		return (1);
	}
	ft_putstr("no");
	return (0);
}
