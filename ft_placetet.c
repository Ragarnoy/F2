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

int	firstalloc(t_tlist *elem)
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

void	remove_t(char str[][13], char letter, int size)
{
	int r;
	int i;
	t_pos p;

	reset_pos(&p);
	i = 0;
	r = 0;
	printf("\n-----------------------\nAVANT\n---------------------\n");
	debug(str, size);
	while (p.x < TABSIZE && r <= size)
	{
		while (p.y < TABSIZE)
		{
			if (str[p.x][p.y] == letter)
				{
					str[p.x][p.y] = '.';
					r++;
				}
			p.y++;
		}
		p.x++;
		p.y = 0;
	}

	debug(str, size);
	printf("\n-----------------------\nAPRES\n---------------------\n");

}

void	debug(char dbug[][13], int s_max)
{
	int i;
	int j;


	i = 0;
	ft_putchar('\n');
	while (i < s_max)
	{
			j = 0;
		while (j < s_max)
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

void		reset_pos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
}

int	tryfit(t_pos *pos, char str[][13], t_tlist *elem)
{
	if (elem)
	{
		pos->x = 0;
		pos->y = 0;
		while(pos->x < pos->s)
		{
			while (pos->y < pos->s)
			{
				if (ft_check_n_put(str, pos, *elem))
				{
					if (tryfit(pos, str, elem->next) == FALSE)
					{
						remove_t(str, elem->letter, pos->s);
						printf("jairm\n");
							sleep(3);
					}
				}
				pos->y++;
			}
			pos->y = 0;
			pos->x++;
		}
		printf("je sors avec :\nx = %i\ny = %i\n", pos->y, pos->x);
		return (FALSE);
	}
	return (NOPE);
}

void	set_map(char str[][13])
{
	int y;
	int x;

	x = 0;
	while (x < 13)
	{
		y = 0;
		while (y < 13)
		{
			str[x][y] = '.';
			y++;
		}
		x++;
	}
}

int			ft_placetet(t_tlist *tetlist)
{
	t_pos	*pos;
	char	str[TABSIZE][TABSIZE];
	int		ret;

	pos = (t_pos*)malloc(sizeof(t_pos));
	pos->x = 0;
	pos->y = 0;
	pos->s = firstalloc(tetlist);
	printf("size is %d\n", pos->s);
	set_map(str);
	debug(str, 13);
	ret = TRUE;
	while ((ret = tryfit(pos, str, tetlist)) != NOPE)
	{
		printf("\n\nbouh\n");
	//sleep(3);
		if (ret == FALSE)
			pos->s++;
	}
	printf("THIS IS FINISH\n");
	debug(str, pos->s);
	return (1);
}
