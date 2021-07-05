# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 22:01:09 by marc              #+#    #+#              #
#    Updated: 2021/07/05 18:25:23 by mterkhoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBS = lib/get_next_line/get_next_line.a lib/libft/libft.a 

SRC_PUSHSWAP =	src/push_swap.c \
				src/tab_to_list.c \
				src/exit.c \
				src/sort.c \
				src/sort_algo.c \
				src/sort_eval.c \
				src/sort_helpers.c \
				src/op_push.c \
				src/op_swap.c \
				src/op_rotate.c \
				src/op_reverse_rotate.c

SRC_CHECKER =	src/checker.c \
				src/tab_to_list.c \
				src/op_push.c \
				src/op_swap.c \
				src/op_rotate.c \
				src/op_reverse_rotate.c \
				src/exit.c

OBJ_PUSHSWAP = $(SRC_PUSHSWAP:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

all: $(NAME_PUSHSWAP)

bonus: $(NAME_PUSHSWAP) $(NAME_CHECKER)

$(NAME_PUSHSWAP): $(OBJ_PUSHSWAP)
	$(MAKE) -C lib/libft/ all
	$(MAKE) -C lib/get_next_line/ all
	$(CC) -o $(NAME_PUSHSWAP) $(OBJ_PUSHSWAP) $(LIBS)

$(NAME_CHECKER): $(OBJ_CHECKER)
	$(CC) -o $(NAME_CHECKER) $(OBJ_CHECKER) $(LIBS)

clean:
	$(MAKE) -C lib/libft/ clean
	$(MAKE) -C lib/get_next_line/ clean
	rm -f $(OBJ_CHECKER)
	rm -f $(OBJ_PUSHSWAP)

fclean: clean
	$(MAKE) -C lib/libft/ fclean
	$(MAKE) -C lib/get_next_line/ fclean
	rm -f $(NAME_CHECKER)
	rm -f $(NAME_PUSHSWAP)

re: fclean all

.PHONY: all bonus clean fclean re
