/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:09:18 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/31 02:32:52 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define BUFFMAX_O 157
# define BUFFMAX_I 547

# include <string.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_tlist
{
	char			letter;
	char			*tetri;
	struct s_tlist	*next;
}					t_tlist;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

int					main(int argc, char *argv[]);
char				*ft_checkshape(char *str);
int					ft_shaper(char **str, int x, int y, int t);
t_tlist				*ft_lstetnew(char letter, char *tetri);
t_tlist				*ft_reader(char *str);

#endif
