/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placetet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:32:28 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/13 17:29:44 by tlernoul         ###   ########.fr       */
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
		return (3);
	if (len == 2)
		return (3);
	while (i * i < (len * 4))
		i++;
	return (i);
}

/*static void	remove_t(char str[][13], char letter)
{
	int r;
	int i;

	i = -1;
	r = 0;
	while (r < 4)
	{
		if (*str[++i] == letter)
			r++;
		if (!*str[i] && (i = 0))
			str++;
	}
}*/

void	debug(char dbug[][13], int s_max)
{
	int i;
	int j;

	j = 0;
	i = 0;
	ft_putchar('\n');
	while (i <= s_max)
	{
		while (j <= s_max)
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

static int	tryfit(t_pos *pos, char str[][13], t_tlist *elem)
{
	if (!elem)
	{
		debug(str, pos->s);
		exit(0);
	}
	while (pos->x <= pos->s && elem)
	{
		while (pos->x <= pos->s && pos->y <= pos->s && elem)
		{
printf("\nCoordinates are %d and %d and size is %d and letter is %c\nCurrent tetri is\n%s\n",pos->x, pos->y, pos->s, elem->letter, elem->tetri);
debug(str, pos->s);
			if (ft_putpiece(str, pos, *elem, 1))
			{
				ft_putpiece(str, pos, *elem, 0);
				tryfit(pos, str, elem->next);
			}
			else if (elem->letter == 'A' && pos->y == pos->s && pos->x == pos->s)
				pos->s++;
			else
				pos->y++;
			tryfit(pos, str, elem);
		}
		pos->y = 0;
		pos->x++;
	}
	return (1);
}

int			ft_placetet(t_tlist *tetlist)
{
	t_pos	*pos;
	char	str[13][13];

	pos = (t_pos*)malloc(sizeof(t_pos));
	pos->x = 0;
	pos->y = 0;
	pos->s = firstalloc(tetlist);
	printf("size is %d\n", pos->s);
	/*pos.s = 0;
	while (tetlist)
	{
	printf("\nSize is %d\nCurrent elem is\n%s\n",pos.s, tetlist->tetri);
	tetlist = tetlist->next;
	}*/
	ft_bzero(str, sizeof(str));
	ft_memset(str, '.', sizeof(str));
	if (!tryfit(pos, str, tetlist))
		return (0);
	ft_putstr("yes");
	return (1);
}
