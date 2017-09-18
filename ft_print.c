/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:18:57 by ccatoire          #+#    #+#             */
/*   Updated: 2017/09/15 12:18:57 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char dbug[][TABSIZE], t_pos *p)
{
	int i;
	int j;

	i = 0;
	while (i < p->s)
	{
			j = 0;
		while (j < p->s)
		{
			ft_putchar(dbug[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	clafaim(char str[][TABSIZE], t_pos *p)
{
	free(p);
	print_map(str, p);
	exit(0);
}