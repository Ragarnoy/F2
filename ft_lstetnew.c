/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstetnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:29:54 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/21 17:12:54 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

tet_list	*ft_lstetnew(char letter, char *content)
{
	tet_list *elem;

	if (!(elem = malloc(sizeof(tet_list))))
		return (NULL);
	if (!(elem->content = malloc(sizeof(elem->content) + 21)))
		return (0);
	if (!(content))
	{
		elem->content = NULL;
		elem->letter = 0;
	}
	else
	{
		ft_memcpy(elem->content, content, 21);
		elem->letter = letter;
	}
	elem->content[21] = '\0';
	elem->next = NULL;
	return (elem);
}
