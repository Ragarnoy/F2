/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:23:56 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/30 11:32:03 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // Enleve cette merde

static int		fillit_cvalid(char *str)
{
	int i;
	int dn;
	int m;

	m = 0;
	i = 0;
	dn = 0;
	while (str[i + m])
	{
		if (str[i + m] == '\n' || str[i + m] == '#')
			dn++;
		if (i == 19)
		{
			if (dn == 8)
			{
				i = 0;
				m += 21;
				dn = 0;
			}
			else
				return (0);
		}
		else
			i++;
	}
	return (1);
}

static int		fillit_square(char *str)
{
	int m;

	m = 0;
	while (str[m])
	{
		if (!(str[4 + m] == '\n' && str[9 + m] == '\n' && str[14 + m] == '\n' &&
					str[19 + m] == '\n'))
			return (0);
		m += 21;
	}
	return (1);
}

static t_tlist	*fillit_chkshp(char *str)
{
	unsigned int	i;
	int				res;
	char			l;
	t_tlist		*elem;
	t_tlist		*begin;

	l = 'A';
	i = 0;
	begin = NULL;
	while (str[i] && (res = ft_checkshape(ft_strsub(str, i, 20))))
	{
		if (!begin)
		{
			elem = ft_lstetnew(l++, res);
			begin = elem;
		}
		else
		{
			elem->next = ft_lstetnew(l++, res);
			elem = elem->next;
		}
		i += 21;
	}
	return ((res) ? begin : NULL);
}

t_tlist		*ft_reader(char *str)
{
	int			i;
	t_tlist	*elem;

	elem = NULL;
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
	printf("\ncvalid =%d", fillit_cvalid(str));
	printf("\nsquare =%d\n", fillit_square(str));
	if (fillit_cvalid(str) && fillit_square(str))
		elem = fillit_chkshp(str);
	if (elem)
		return (elem);
	return (NULL);
}
