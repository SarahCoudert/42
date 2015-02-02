# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 16:10:00 by scoudert          #+#    #+#              #
#    Updated: 2015/02/02 13:32:02 by scoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror

DEBUG =$(CFLAGS) -g

NAME=libft.a

CC=gcc

SRC= ft_lstdel.c ft_memdel.c ft_putnbr_fd.c ft_strdel.c ft_strmap.c \
ft_strrchr.c ft_toupper.c ft_atoi.c ft_lstdelone.c ft_memmove.c ft_putstr.c \
ft_strdup.c ft_strmapi.c ft_strrev.c ft_bzero.c ft_lstnew.c ft_memset.c \
ft_putstr_fd.c ft_strequ.c ft_strncat.c ft_strsplit.c ft_isalnum.c \
ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c ft_strncmp.c ft_strstr.c\
ft_isalpha.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c ft_striteri.c \
ft_strncpy.c ft_strsub.c ft_isascii.c ft_memchr.c ft_putendl.c ft_strclr.c\
ft_strjoin.c ft_strnequ.c ft_strtrim.c ft_isdigit.c ft_memcmp.c \
ft_putendl_fd.c ft_strcmp.c ft_strlcat.c ft_strnew.c ft_swap.c ft_memcpy.c\
ft_lstaddend.c ft_lstcountbytes.c del.c ft_itoa.c ft_lstiter.c ft_lstmap.c \
ft_lstcountelements.c ft_putnbr.c ft_strlen.c ft_strnstr.c ft_tolower.c \
ft_isprint.c ft_strcpy.c ft_lstadd.c get_next_line.c ft_tabnew.c \
ft_count_word.c ft_putn.c

HEADER=./includes

OBJ=$(SRC:.c=.o)

RM=rm -f

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@echo "\033[32mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[36mCreate libft.a \033[0m"
	@ranlib $(NAME)

clean:
	@echo "\033[31mDelete all \".o\"\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@echo "\033[31mDelete libft.a\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@echo "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[36mCreate libft.a \033[0m"
	@ranlib $(NAME)
