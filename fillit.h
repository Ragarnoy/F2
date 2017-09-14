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
# define FALSE	-42
# define TRUE	42
# define NOPE	69
# define TABSIZE	13

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
int					ft_putpiece(char grid[][13], t_pos *pos, t_tlist elem);
int					ft_placetet(t_tlist *tetlist);
char				*ft_checkshape(char *str);
char				**ft_realloc(char **str, size_t size);
t_tlist				*ft_lstetnew(char letter, char *tetri);
t_tlist				*ft_reader(char *str);


int		ft_check_n_put(char grid[][13], t_pos *pos, t_tlist elem);
int		ft_check_place(char grid[][13], t_pos *pos, t_tlist elem);
void	remove_t(char str[][13], char letter, int size);
void	reset_pos(t_pos *pos);

void	set_map(char str[13][13]);
void	debug(char dbug[][13], int s_max);
#endif
