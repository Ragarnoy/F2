/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:09:18 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/11 11:43:18 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define BUFFMAX_O 122
# define BUFFMAX_I 547

# include <string.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

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
	int				s;
}					t_pos;

int					main(int argc, char *argv[]);
int					ft_shaper(char **str, int x, int y, int t);
int					ft_putpiece(char grid[][13], t_pos *pos, t_tlist elem,
																	int check);
int					ft_placetet(t_tlist *tetlist);
char				*ft_checkshape(char *str);
char				**ft_realloc(char **str, size_t size);
t_tlist				*ft_lstetnew(char letter, char *tetri);
t_tlist				*ft_reader(char *str);

#endif
