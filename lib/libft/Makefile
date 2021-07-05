# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 22:01:09 by marc              #+#    #+#              #
#    Updated: 2021/05/23 09:54:29 by mterkhoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror

SRC =	ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_min.c		\
		ft_strlen.c		\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_strcpy.c		\
		ft_strlcpy.c	\
		ft_strcat.c		\
		ft_strlcat.c	\
		ft_strdup.c		\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_atoi.c		\
		ft_atol.c		\
		ft_isspace.c	\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_memccpy.c	\
		ft_memcmp.c		\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_strnstr.c	\
		ft_calloc.c		\
		ft_itoa.c		\
		ft_strjoin.c	\
		ft_split.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putnbr_fd.c	\
		ft_putendl_fd.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_strmapi.c	\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_lstjoin.c			\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
