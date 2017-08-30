/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstetnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:29:54 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/30 11:20:42 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_tlist	*ft_lstetnew(char letter,int id)
{
	t_tlist *elem;

	if (!(elem = malloc(sizeof(t_tlist))))
		return (NULL);
	if (!(letter) || !(id))
	{
		elem->id = 0;
		elem->letter = 0;
	}
	else
	{
		elem->id = id;
		elem->letter = letter;
	}
	elem->next = NULL;
	return (elem);
}
