/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 15:57:35 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/26 17:50:02 by tlernoul         ###   ########.fr       */
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
	while ((end = read(fd, buf, BUFFMAX_I)) > 0)
		buf[end] = '\0';
	if ((close(fd)) == -1)
		return (0);
	tmp = ft_strsub(buf, 0, ft_strlen(buf));
	free(buf);
	return (tmp);
}
