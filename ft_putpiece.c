/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shaper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 19:00:44 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/07 16:20:54 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_putpiece(char grid[][12], t_pos *pos, t_tlist elem, int check)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = pos->y;
	x = pos->x;
	while (elem.tetri[i])
	{
		if (elem.tetri[i] == '\n')
		{
			x++;
			y = pos->y;
		}
		else
		{
			if (grid[x][y] == '#' && elem.tetri[i] == '#' && check)
				return (0);
			else if (elem.tetri[i] == '#' && !check)
				grid[x][y] = elem.letter;
			y++;
		}
		i++;
	}
	return (1);
}
