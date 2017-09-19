NAME	=	fillit

SRC		=	main.c					\
			$(WAY)fillit.c 			\
			$(WAY)ft_init.c 		\
			$(WAY)ft_init2.c 		\
			$(WAY)ft_checkshape.c 	\
			$(WAY)ft_print.c 		\
			$(WAY)ft_check_n_put.c

WAY	=	


LIBPATH	=	./libft/

HEADLIBPATH	=	./libft/includes/

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADLIBPATH)

CCLIB		=	-L libft/ -lft

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		: $(OBJ)
				$(MAKE) -C $(LIBPATH) libft.a
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIB) -I $(HEADLIBPATH)

lib			:	libft/libft.a
			@(cd libft && $(MAKE))

dellib		:
			@(cd libft && $(MAKE) fclean)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

relib		:
			@(cd libft && $(MAKE) re)

re			:	fclean $(NAME)

.PHONY		:	all re clean fclean
