# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 22:01:09 by marc              #+#    #+#              #
#    Updated: 2021/07/05 15:43:24 by mterkhoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBS = lib/get_next_line/get_next_line.a lib/libft/libft.a 

SRC_CHECKER =	src/checker.c \
				src/operations.c \
				src/operations2.c \
				src/lists.c \
				src/helpers.c
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
				src/op_reverse_rotate.c \

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
OBJ_PUSHSWAP = $(SRC_PUSHSWAP:.c=.o)

all: $(NAME_PUSHSWAP)

bonus: $(NAME_PUSHSWAP) $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJ_CHECKER)
	$(MAKE) -C lib/libft/ all
	$(MAKE) -C lib/get_next_line/ all
	$(CC) -o $(NAME_CHECKER) $(OBJ_CHECKER) $(LIBS)

$(NAME_PUSHSWAP): $(OBJ_PUSHSWAP)
	$(MAKE) -C lib/libft/ all
	$(MAKE) -C lib/get_next_line/ all
	$(CC) -o $(NAME_PUSHSWAP) $(OBJ_PUSHSWAP) $(LIBS)

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
