/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shaper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 19:00:44 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/06 18:26:49 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_putpiece(char grid[][12], t_pos *pos, char *str, int check)
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
			x++;
			y = pos->y;
		}
		else
		{
			if (grid[x][y] == '#' && str[i] == '#' && check)
				return (0);
			else if (str[i] == '#' && !check)
				grid[x][y] = '#';
			y++;
		}
		i++;
	}
	return (1);
}
