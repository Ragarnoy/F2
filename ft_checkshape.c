/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkshape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:34:11 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/18 18:42:36 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char	*l_shape(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 5] == '#' &&
				str[i + 10] == '#')
			return ("##\n#\n#");
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 7] == '#')
			return ("###\n..#");
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' &&
				str[i + 9] == '#')
			return (".#\n.#\n##");
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' &&
				str[i + 7] == '#')
			return ("#\n###");
		i++;
	}
	return (0);
}

static char	*l_shape2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 6] == '#' &&
				str[i + 11] == '#')
			return ("##\n.#\n.#");
		if (str[i] == '#' && str[i + 3] == '#' && str[i + 4] == '#' &&
				str[i + 5] == '#')
			return ("..#\n###");
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' &&
				str[i + 11] == '#')
			return ("#\n#\n##");
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 5] == '#')
			return ("###\n#");
		i++;
	}
	return (0);
}

static char	*s_shape(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 6] == '#' &&
				str[i + 7] == '#')
			return ("##\n.##");
		if (str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' &&
				str[i + 9] == '#')
			return (".#\n##\n#");
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 4] == '#' &&
				str[i + 5] == '#')
			return (".##\n##");
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' &&
				str[i + 11] == '#')
			return ("#\n##\n.#");
		i++;
	}
	return (0);
}

static char	*t_shape(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' &&
				str[i + 6] == '#')
			return (".#\n###");
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' &&
				str[i + 10] == '#')
			return ("#\n##\n#");
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 6] == '#')
			return ("###\n.#");
		if (str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' &&
				str[i + 10] == '#')
			return (".#\n##\n.#");
		i++;
	}
	return (0);
}

char		*ft_checkshape(char *str)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (str[i] && !tmp)
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 5] == '#' &&
				str[i + 6] == '#')
			tmp = "##\n##";
		else if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 3] == '#')
			tmp = "####";
		else if (str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' &&
				str[i + 15] == '#')
			tmp = "#\n#\n#\n#";
		i++;
	}
	tmp = (!tmp) ? l_shape(str) : tmp;
	tmp = (!tmp) ? l_shape2(str) : tmp;
	tmp = (!tmp) ? s_shape(str) : tmp;
	tmp = (!tmp) ? t_shape(str) : tmp;
	ft_memdel((void **)&str);
	return (tmp);
}
