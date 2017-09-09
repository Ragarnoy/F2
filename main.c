/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:17:29 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/09 19:50:43 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_buffer(char *pth)
{
	int fd;
	int end;
	char *buf;
	char *tmp;

	if ((fd = open(pth, O_RDONLY)) == -1 || !(buf = ft_strnew(BUFFMAX_I)))
		return (0);
	end = read(fd, buf, BUFFMAX_I);
	buf[end] = '\0';
	if ((close(fd)) == -1)
		return (0);
	tmp = ft_strsub(buf, 0, ft_strlen(buf));
	free(buf);
	return (tmp);
}

int			main(int argc, char *argv[])
{
	int			i;
	t_tlist		*elem;
	char *str;

	str = ft_buffer(argv[1]);
	i = 0;
	if (argc != 2)
		return (0);
	if ((elem = ft_reader(str)))
	{
		ft_placetet(elem);
		ft_putstr("\nFinal yes\n");
		return (1);
	}
	ft_putstr("no");
	return (0);
}
