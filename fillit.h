/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:09:18 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/30 11:21:52 by tlernoul         ###   ########.fr       */
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

typedef struct		f_list
{
	char			letter;
	int				id;
	struct f_list	*next;
}					t_tlist;

int					main(int argc,char *argv[]);
t_tlist			*ft_reader(char *str);
int					ft_checkshape(char *str);
char				*ft_buffer(char *pth);
t_tlist			*ft_lstetnew(char letter,int id);

#endif
