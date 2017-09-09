/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:23:56 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/09 20:02:31 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		fillit_square(char *str)
{
	size_t m;

	m = 0;
	while (m < ft_strlen(str))
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
	char			*tmp;
	char			l;
	t_tlist		*elem;
	t_tlist		*begin;

	l = 'A';
	i = 0;
	begin = NULL;
	while (i < ft_strlen(str) && (tmp = ft_checkshape(ft_strsub(str, i, 20))))
	{
		printf("%c\n", str[i]);
	printf("\n====\n%s\n", tmp);
		if (!begin)
		{
			elem = ft_lstetnew(l++, tmp);
			begin = elem;
		}
		else
		{
			elem->next = ft_lstetnew(l++, tmp);
			elem = elem->next;
		}
		i += 21;
	}
	return ((tmp) ? begin : NULL);
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
	printf("%d total characters", i);
	if (fillit_square(str))
		elem = fillit_chkshp(str);
	if (elem)
		return (elem);
	return (NULL);
}
