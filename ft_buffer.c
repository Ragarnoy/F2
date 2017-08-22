/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 15:57:35 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/19 19:54:21 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_buffer(char *pth)
{
	int fd;
	int end;
	char *buf;

	buf = ft_strnew(520);
	if ((fd = open(pth, O_RDONLY)) == -1)
		return (0);
	while ((end = read(fd, buf, 521)) > 0)
		buf[end] = '\0';
	if ((close(fd)) == -1)
		return (0);
	return (buf);
}
