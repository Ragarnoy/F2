/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placetet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:32:28 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/06 14:50:28 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**firstalloc(char **str)
{
	int i;
	char **tmp;

	i = 0;
	if (!(str = (char**)malloc(sizeof(str) * 3)))
		return (NULL);
	else
		while (i < 2)
		{
			str[i] = ft_strnew(3);
			str[i] = ft_memset(str[i], '.', 2);
			i++;
		}
	str[2] = 0;
	return (str);
}

static int	tryfit(t_pos pos, char **str, t_tlist *elem)
{
	while (str[++pos.x])
	{
		while (str[pos.x][++pos.y] && ft_putpiece(str, &pos, &elem->letter, 1))
		{
			if (ft_putpiece(str, &pos, elem->tetri, 1))
			{
				ft_putpiece(str, &pos, elem->tetri, 0);
				elem = elem->next;
			}
			pos.y++;
		}
	}
	return (1);
}

static void	recurfit(t_pos pos, t_tlist *elem)
{

}

int			ft_placetet(t_tlist *tetlist)
{
	t_pos	pos;
	size_t	size;
	char	**str;

	pos.x = -1;
	pos.y = -1;
	size = 2;
	ft_bzero(&pos, sizeof(t_pos));
	str = firstalloc(str);
	while (!tryfit(pos, str, tetlist))
		ft_realloc(str, size);
	return (1);
}
