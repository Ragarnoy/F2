/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placetet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:32:28 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/31 02:57:49 by tlernoul         ###   ########.fr       */
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

static void	tryfit(t_pos pos)
{
	int x;

	x = 0;
	while (str[])
	{
	}
}

int			ft_placetet(t_tlist tetlist)
{
	t_pos	*pos;
	size_t	size;
	char	**str;

	size = 2;
	ft_bzero(pos, sizeof(t_pos));
	str = firstalloc(str);
	while (str[pos->x])
	{
		pos->y = 0;
		pos->x++;
	}
	return (1);
}
