/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkshape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:34:11 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/30 11:25:51 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	l_shape(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 5] == '#' &&
				str[i + 10] == '#')
			return (4);
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 7] == '#')
			return (5);
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' &&
				str[i + 9] == '#')
			return (6);
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' &&
				str[i + 7] == '#')
			return (7);
		i++;
	}
	return (0);
}

static int	l_shape2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 6] == '#' &&
				str[i + 11] == '#')
			return (8);
		if (str[i] == '#' && str[i + 3] == '#' && str[i + 4] == '#' &&
				str[i + 5] == '#')
			return (9);
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' &&
				str[i + 11] == '#')
			return (10);
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 5] == '#')
			return (11);
		i++;
	}
	return (0);
}

static int	s_shape(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 6] == '#' &&
				str[i + 7] == '#')
			return (12);
		if (str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' &&
				str[i + 9] == '#')
			return (13);
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 4] == '#' &&
				str[i + 5] == '#')
			return (14);
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' &&
				str[i + 11] == '#')
			return (15);
		i++;
	}
	return (0);
}

static int	t_shape(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' &&
				str[i + 6] == '#')
			return (16);
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' &&
				str[i + 10] == '#')
			return (17);
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 6] == '#')
			return (18);
		if (str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' &&
				str[i + 10] == '#')
			return (19);
		i++;
	}
	return (0);
}

int			ft_checkshape(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 5] == '#' &&
				str[i + 6] == '#')
			return (1);
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 3] == '#')
			return (2);
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' &&
				str[i + 15] == '#')
			return (3);
		i++;
	}
	if ((i = l_shape(str)) || (i = l_shape2(str)) || (i = s_shape(str))
			|| (i = t_shape(str)))
	{
		free(str);
		return (i);
	}
	return (0);
}
