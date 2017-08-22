/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:23:56 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/21 15:29:54 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	fillit_cvalid(char *str)
{
	int i;
	int dn;
	int m;

	m = 0;
	i = 0;
	dn = 0;
	while (str[i + m + 1])
	{
		if (str[i + m] == '\n' || str[i + m] == '#')
			dn++;
		if (i == 19)
		{
			if (((i + 1) * dn) == 160)
			{
				i = 0;
				m = m + 21;
				dn = 0;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	fillit_square(char *str)
{
	int m;

	m = 0;
	while (str[m])
	{
		if (!(str[4 + m] == '\n' && str[9 + m] == '\n' && str[14 + m] == '\n' &&
					str[19 + m] == '\n'))
			return (0);
		m = m + 21;
	}
	return (1);
}

static int	fillit_chkshp(char *str)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (!(res = ft_checkshape(ft_strsub(str, i, 20))))
			return (0);
		i = i + 21;
	}
	return (res);
}

int			ft_reader(char *str)
{
	int i;

	i = 0;
	if (!(str))
		return (0);
	while (str[i + 1])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		if (!(str[i + 2]) && str[i] == '\n')
			return (0);
		i++;
	}
	printf("\n%d", i);
	printf("\ncvalid =%d\n", fillit_cvalid(str));
	printf("\nsquare =%d\n", fillit_square(str));
	printf("\nchkshp =%d\n", fillit_chkshp(str));
	if (fillit_cvalid(str) && fillit_square(str) && fillit_chkshp(str))
		return (1);
	return (0);
}
