/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shaper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 19:00:44 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/13 16:48:28 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int		chr_is_uppercase(char str)
{
	if (!(str >= 'A' && str <= 'Z'))
		return (0);
	return (1);
}*/

int		ft_putpiece(char grid[][13], t_pos *pos, t_tlist elem, int check)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = pos->y;
	x = pos->x;
	//printf("\ncoord = X=%d Y=%d -- current char is %c --chkmd=%d\n", x, y, elem.letter, check);
	while (elem.tetri[i])
	{
		if (elem.tetri[i] == '\n')
		{
			x++;
			y = pos->y;
		}
		else
		{
	//printf("coord = X=%d Y=%d\n", x, y);
			if (x > pos->s || y > pos->s)
				return (0);
			if (grid[x][y] != '.' && elem.tetri[i] != '.' && check)
			{
				ft_putstr("^^^^^^^^^----Not fit");
				return (0);
			}
			else if (elem.tetri[i] != '.' && !check)
				grid[x][y] = elem.letter;
			y++;
		}
		i++;
	}
	ft_putchar('1');
	return (1);
}
