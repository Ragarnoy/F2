/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shaper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 19:00:44 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/30 13:29:10 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	l_shape(char **str, int x, int y)
{
	if (str[x][y] == '.' && str[x + 1][y] == '.' && str[x][y + 1] == '.' &&
			str[x][y + 2] == '.')
		return (4);
	if (str[x][y] == '.' && str[x + 1][y] == '.' && str[x + 2][y] == '.' &&
			str[x + 1][y + 2] == '.')
		return (5);
	if (str[x + 1][y] == '.' && str[x + 1][y + 1] == '.' && str[x][y + 2] == '.'
			&& str[x + 1][y + 2] == '.')
		return (6);
	if (str[x][y] == '.' && str[x][y + 1] == '.' && str[x + 1][y + 1] == '.'
			&& str[x + 2][y + 1] == '.')
		return (7);
	else
		return (0);
}

static int	li_shape(char **str, int x, int y)
{
	if (str[x][y] == '.' && str[x + 1][y] == '.' && str[x + 1][y + 1] == '.'
			&& str[x + 1][y + 2] == '.')
		return (8);
	if (str[x + 2][y] == '.' && str[x][y + 1] == '.' && str[x + 1][y + 1] == '.'
			&& str[x + 2][y + 1] == '.')
		return (9);
	if (str[x][y] == '.' && str[x][y + 1] == '.' && str[x][y + 2] == '.'
			&& str[x + 1][y + 2] == '.')
		return (10);
	if (str[x][y] == '.' && str[x + 1][y] == '.' && str[x + 2][y] == '.'
			&& str[x][y + 1] == '.')
		return (8);
	else
		return (0);
}

static int	s_shape(char **str, int x, int y)
{
	if (str[x][y] == '.' && str[x + 1][y] == '.' && str[x + 1][y + 1] == '.'
			&& str[x + 2][y + 1] == '.')
		return (12);
	if (str[x + 1][y] == '.' && str[x][y + 1] == '.' && str[x][y + 2] == '.'
			&& str[x + 1][y + 1] == '.')
		return (13);
	if (str[x + 1][y] == '.' && str[x + 2][y] == '.' && str[x][y + 1] == '.'
			&& str[x + 1][y + 1] == '.')
		return (14);
	if (str[x][y] == '.' && str[x][y + 1] == '.' && str[x + 1][y + 1] == '.'
			&& str[x + 1][y + 2] == '.')
		return (15);
	else
		return (0);
}

static int	t_shape(char **str, int x, int y)
{
	if (str[x + 1][y] == '.' && str[x][y + 1] == '.' && str[x + 1][y + 1] == '.'
			&& str[x + 2][y + 1] == '.')
		return (16);
	if (str[x][y] == '.' && str[x][y + 1] == '.' && str[x + 1][y + 1] == '.'
			&& str[x][y + 2] == '.')
		return (17);
	if (str[x][y] == '.' && str[x + 1][y] == '.' && str[x + 1][y + 1] == '.'
			&& str[x + 2][y] == '.')
		return (18);
	if (str[x + 1][y] == '.' && str[x][y + 1] == '.' && str[x + 1][y + 1] == '.'
			&& str[x + 1][y + 2] == '.')
		return (19);
	else
		return (0);
}

int			ft_shaper(char **str, int x, int y, int t)
{
	if (t == 1)
		if (str[x][y] == '.' && str[x + 1][y] == '.' && str[x][y + 1] == '.' &&
				str[x + 1][y + 1] == '.')
			return (1);
	if (t == 2)
		if (str[x][y] == '.' && str[x + 1][y] == '.' && str[x + 2][y] == '.' &&
				str[x + 3][y] == '.')
			return (2);
	if (t == 3)
		if (str[x][y] == '.' && str[x][y + 1] == '.' && str[x][y + 2] == '.' &&
				str[x][y + 3] == '.')
			return (3);
	if (t >= 4 || t <= 19)
	{
		if (t != l_shape(str, x, y) || t != li_shape(str, x, y) ||
				t != s_shape(str, x, y) || t != t_shape(str, x, y))
			return (0);
		else
			return (1);
	}
	else
		return (0);
}
