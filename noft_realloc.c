/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:19:41 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/30 12:44:15 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_realloc(char **str,size_t size)
{
	char **tmp;
	int x;

	x = 0;
	if (!(tmp = (char**)malloc(sizeof(*tmp) * (size + 2))))
		return (0);
	while (tmp[x])
	{
		tmp[x] = ft_strnew(size + 2);
		tmp[x] = ft_memset(tmp, '.', size + 2);
		x++;
	}
	ft_strdel(str);

	return (tmp);
}
