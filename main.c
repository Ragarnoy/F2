/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2017/09/15 12:24:32 by ccatoire          #+#    #+#             */
/*   Updated: 2017/09/18 18:42:26 by tlernoul         ###   ########.fr       */
=======
/*   Created: 2017/08/14 13:17:29 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/11 19:16:17 by tlernoul         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	t_tlist	*elem;
	char	*str;

<<<<<<< HEAD
=======
	if ((fd = open(pth, O_RDONLY)) == -1 || !(buf = ft_strnew(BUFFMAX_I)))
		return (0);
	if (!(end = read(fd, buf, BUFFMAX_I)))
		return (0);
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

	i = 0;
>>>>>>> master
	if (argc != 2)
	{
		print_use(USE);
		return (0);
<<<<<<< HEAD
	}
	if (!(str = ft_buffer(argv[1])))
	{
		print_use(ERR);
		return (0);
	}
=======
	str = ft_buffer(argv[1]);
>>>>>>> master
	if ((elem = ft_reader(str)))
	{
		free(str);
		ft_placetet(elem);
	}
	print_use(ERR);
	return (0);
}
