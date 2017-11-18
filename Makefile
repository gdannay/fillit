# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:39:26 by clegirar          #+#    #+#              #
#    Updated: 2017/11/16 18:26:02 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRCS	=	fillit.c		\
			check.c			\
			algo.c			\
			create_list.c	\
			fct_manage.c	\
			manage_bloc.c	\
			fill_algo.c		\
			check_cp.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I./libft/ -I./

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C libft
			$(CC) $(OBJS) -L libft -lft -o $(NAME)

%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAGS)

clean	:
			make clean -C libft
			rm -rf $(OBJS)

fclean	:
			make fclean -C libft
			rm -rf $(OBJS) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
