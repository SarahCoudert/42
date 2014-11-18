# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 16:10:00 by scoudert          #+#    #+#              #
#    Updated: 2014/11/18 15:07:05 by scoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

SRC= ft_lstdel.c ft_memdel.c ft_putnbr_fd.c ft_strdel.c ft_strmap.c \
ft_strrchr.c ft_toupper.c ft_atoi.c ft_lstdelone.c ft_memmove.c ft_putstr.c \
ft_strdup.c ft_strmapi.c ft_strrev.c ft_bzero.c ft_lstnew.c ft_memset.c \
ft_putstr_fd.c ft_strequ.c ft_strncat.c ft_strsplit.c ft_isalnum.c \
ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c ft_strncmp.c ft_strstr.c\
ft_isalpha.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c ft_striteri.c \
ft_strncpy.c ft_strsub.c ft_isascii.c ft_memchr.c ft_putendl.c ft_strclr.c\
ft_strjoin.c ft_strnequ.c ft_strtrim.c ft_isdigit.c ft_memcmp.c \
ft_putendl_fd.c ft_strcmp.c ft_strlcat.c ft_strnew.c ft_swap.c

OBJ=$(SRC:.c=.o)

RM=rm -f

.PHONY: all, clean, fclean, re

all:
	make $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
