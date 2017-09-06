/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placetet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:32:28 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/06 18:33:52 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	firstalloc(t_tlist *elem)
{
	int		i;
	size_t	len;
	char	**tmp;

	i = 0;
	while (elem)
		len++;
	if (len == 1)
		return (2);
	if (len == 2)
		return (3);
	while (i * i < (len * 4))
		i++;
	return (i);
}

static int	tryfit(t_pos pos, char str[][12], t_tlist *elem, size_t sizemax)
{
	while (str[++pos.x] && pos.x < sizemax)
	{
		while (str[pos.x][++pos.y] && ft_putpiece(str, &pos, &elem->letter, 1)
				&& pos.y < sizemax)
		{
			if (ft_putpiece(str, &pos, elem->tetri, 1))
			{
				ft_putpiece(str, &pos, elem->tetri, 0);
				elem = elem->next;
			}
		}
	}
	return (1);
}

int			ft_placetet(t_tlist *tetlist)
{
	t_pos	pos;
	size_t	sizemax;
	char	str[12][12];

	pos.x = -1;
	pos.y = -1;
	ft_memset(&str, '.', 12);
	ft_bzero(&pos, sizeof(t_pos));
	sizemax = firstalloc(tetlist);
	if (!tryfit(pos, str, tetlist, sizemax))
		return (0);
	return (1);
}
