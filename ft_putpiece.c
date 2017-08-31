/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shaper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 19:00:44 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/31 01:13:01 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_putpiece(char **grid, t_pos *pos, char *str, int check)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = pos->y;
	x = pos->x;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			y++;
			x = pos->x;
		}
		else
		{
			if (grid[x][y] == '#' && str[i] == '#' && check)
				return (0);
			else if (str[i] == '#' && !check)
				grid[x][y] = '#';
			x++;
		}
		i++;
	}
	return (1);
}
