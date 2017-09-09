/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstetnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:29:54 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/09 19:27:30 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tlist	*ft_lstetnew(char letter, char *tetri)
{
	t_tlist *elem;

	if (!(elem = malloc(sizeof(t_tlist))))
		return (NULL);
	if (!(elem->tetri = ft_strnew(7)))
		return (NULL);
	if (!(letter) || !(tetri))
	{
		elem->tetri = NULL;
		elem->letter = 0;
	}
	else
	{
		elem->tetri = tetri;
		elem->letter = letter;
	}
	elem->next = NULL;
	return (elem);
}
