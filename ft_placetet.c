/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placetet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:32:28 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/09 20:31:33 by tlernoul         ###   ########.fr       */
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
		return (3);		//Euh pardon ? XD
	if (len == 2)
		return (3);
	while (i * i < (len * 4))
		i++;
	return (i);
}

static void	remove_t(char str[][13], char letter)
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
}

void	debug(char dbug[][13], int s_max)
{
	int i;
	int j;


	i = 0;
	ft_putchar('\n');
	while (i <= s_max)
	{
			j = 0;
		while (j <= s_max)
		{
			printf("%c", dbug[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_putchar('\n');
}

t_pos	get_pos(char str[][13], char letter)
{
	int y;
	int x;
	t_pos p;

	p.x = 0;
	p.y = 0;
	x = 0;
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			if (str[x][y] == letter)
			{
				p.x = x;
				p.y = y;
				return (p);
			}
			y++;
		}
	}
	return (p);
}

/*
	main_algo
		->while pas fini, test from smallest to biggest
	test_algo
		->if no tetris left, return true
		->while positions not tested, test this position
			->if fit, then call test_algo for next tetriminos => catch true, return true
			->if catched false, rm tetri from position, continue to test
		->return false
*/



static int	tryfit(t_pos *pos, char str[][13], t_tlist *elem)
{
	if (elem)
	{
		sleep(1);
		printf("Size = %d\ny = %d\nx = %d\n-------\n", pos->s, pos->y, pos->x);
		if (ft_putpiece(str, pos, *elem, 1))
		{
			printf("\n------\nPLACE : %c\n-----\n", elem->letter);
			ft_putpiece(str, pos, *elem, 0);
			if (tryfit(pos, str, elem->next) == 1)
				return (1);
			else
			{
				pos.y++;
			}
		}
		return (0);
	// 	else
	// 		pos->y++;
	// 	if (pos->y >= pos->s)
	// 		{
	// 			pos->x++;
	// 			pos->y = 0;
	// 		}
	// 	if (pos->x >= pos->s)
	// 	{
	// 		printf("\n------\nREMOVE : %c\n-----\n", elem->letter - 1);
	// 		*pos = get_pos(str, elem->letter - 1);
	// 		remove_t(str, elem->letter - 1);
	// 		pos->y++;
	// 		return (0);
	// 	}
	// 	tryfit(pos, str, elem);
	// }
	// debug(str, pos->s);
	// exit(0);
}

void		pritab(char tab[13][13])
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
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
	ft_bzero(str, sizeof(str));				//sizeof?
	ft_memset(str, '.', sizeof(str));		//pourquoi bzero et memset?
	tryfit(pos, str, tetlist);
	printf("THIS IS FINISH\n");
	debug(str, pos->s);
	return (1);
}
