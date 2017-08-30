/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placetet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:32:28 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/30 13:09:31 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**firstalloc(char **str)
{
	int i;
	char **tmp;

	i = 0;
	if (!(str = (char**)malloc(sizeof(str) * 3)))
		return (NULL);
	else
		while (i < 2)
		{
			str[i] = ft_strnew(3);
			str[i] = ft_memset(str[i], '.', 2);
			i++;
		}
	str[2] = 0;
	return (str);
}

static void	tryfit(char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
	}
}

int			ft_placetet(t_tlist tetlist)
{
	int		x;
	int		y;
	size_t	size;
	char	**str;

	size = 2;
	x = 0;
	y = 0;
	str = firstalloc(str);
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			y++;
		}
		x++;
	}
	return (1);
}
