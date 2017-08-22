/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:09:18 by tlernoul          #+#    #+#             */
/*   Updated: 2017/08/21 16:30:44 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <string.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct		f_list
{
	char			letter;
	char			*content;
	struct s_list	*next;
}					tet_list;

int					main(int argc, char *argv[]);
int					ft_reader(char *str);
int					ft_checkshape(char *str);
char				*ft_buffer(char *pth);
tet_list			*ft_lstetnew(char letter, char *content);

#endif
