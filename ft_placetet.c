/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placetet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:32:28 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/07 17:39:07 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	firstalloc(t_tlist *elem)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (elem)
	{
		elem = elem->next;
		len++;
	}
	if (len == 1)
		return (2);
	if (len == 2)
		return (3);
	while (i * i < (len * 4))
		i++;
	return (i);
}

static void	debug(char dbug[][13], int s_max)
{
	int i;
	int j;

	j = 0;
	i = 0;
	ft_putchar('\n');
	while (i < s_max)
	{
		while (j < s_max)
		{
			printf("%c", dbug[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
	ft_putchar('\n');
}

static int	tryfit(t_pos pos, char str[][13], t_tlist *elem, int sizemax)
{
	pos.x = -1;
	pos.y = -1;
	if (!elem)
		debug(str, sizemax);
	printf("\nCoordinates are %d and %d and size is %d\nCurrent elem is\n%s\n",pos.x, pos.y, sizemax, elem->tetri);
	while (++pos.x <= sizemax && elem)
	{
		while (++pos.y <= sizemax && elem)
		{
			if (ft_putpiece(str, &pos, *elem, 1))
			{
				ft_putpiece(str, &pos, *elem, 0);
				tryfit(pos, str, elem->next, sizemax);
			}
		}
		if (pos.x == sizemax && pos.y == sizemax && elem)
			sizemax++;
		pos.y = -1;
	}
	return (1);
}

int			ft_placetet(t_tlist *tetlist)
{
	t_pos	pos;
	int		sizemax;
	char	str[13][13];

	ft_bzero(str, sizeof(str));
	ft_memset(str, '.', sizeof(str) - 1);
	ft_bzero(&pos, sizeof(t_pos));
	sizemax = firstalloc(tetlist);
	if (!tryfit(pos, str, tetlist, sizemax))
		return (0);
	printf("\n\nstr is %s\n", str[0]);
	printf("size is %d\n", sizemax);
	ft_putstr("yes");
	return (1);
}
