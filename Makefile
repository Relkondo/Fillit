# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:44:30 by scoron            #+#    #+#              #
#    Updated: 2018/12/05 20:26:11 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

S_NAME = main.c \
	   check_pieces.c \
	   check_file.c \
	   support_check.c \
	   solve.c \
	   move_piece.c \
	   scan_holes.c \
	   check_hole.c \
	   support_holes.c \
	   display.c \
	   ft_putstab_visual.c\

S_PATH = src/

SRCS = $(addprefix $(S_PATH), $(S_NAME))

O_PATH = obj/

OBJS = $(addprefix $(O_PATH), $(S_NAME:.c=.o))

HEADER = fillit.h

FLAGS = -Wall -Wextra -Werror

L_PATH = libft/

LIB = $(addprefix $(S_PATH), $(L_PATH))

all : $(NAME)

$(NAME) : lib $(OBJS)
	@gcc -o $(NAME) $(OBJS) $(FLAGS) -I libft/includes -L $(LIB) -lft

$(O_PATH)%.o : $(S_PATH)%.c includes/$(HEADER)
	@mkdir -p $(O_PATH)
	@clang $(FLAGS) -I includes -c $< -o $@

clean :
	@make -C $(LIB) clean
	@/bin/rm -rf $(O_PATH)

fclean : clean
	@make -C $(LIB) fclean
	@/bin/rm -f $(NAME)

re : fclean all

lib :
	@make -C libft/

push : fclean
	@git add -A
	@git commit -m "quick push"
	@git push origin master
	git status

.PHONY: all, clean, fclean, re, push, lib
