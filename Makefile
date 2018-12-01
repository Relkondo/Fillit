# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:44:30 by scoron            #+#    #+#              #
#    Updated: 2018/12/01 21:22:48 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = check_pieces.c \
	   solve.c \
	   main.c \
	   affichage.c \
	   move_piece.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		@gcc -o $(NAME) $(OBJS) -I libft/includes -L libft/ -lft

%.o : %.c
	@gcc -Wall -Wextra -Werror -I libft/includes -c $< -o $@

clean :
	@/bin/rm -f $(OBJS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

lib :
	@make -C libft/ fclean && make -C libft/

push : fclean
	@git add -A
	@git commit -m "quick push"
	@git push origin master
	git status

.PHONY: all, clean, fclean, re, push, lib
