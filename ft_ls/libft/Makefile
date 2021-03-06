# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 16:10:00 by scoudert          #+#    #+#              #
#    Updated: 2015/03/10 19:43:50 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

DEBUG = $(CFLAGS) -g

CFLAGS=-Wall -Wextra -Werror

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
ft_isprint.c ft_strcpy.c ft_lstadd.c tab_merge_sort.c char_sort.c \
ft_putn.c ft_lstadd_db.c ft_lstdel_db.c ft_lstdelall_db.c ft_lstdellone_db.c \
ft_lstdelone_db.c ft_lstgetend_db.c ft_lstgetstart_db.c ft_lstgo_n_next.c \
ft_lstgo_n_prev.c ft_lstlen.c ft_lstlen_db.c ft_lstnew_db.c ft_lsttochar_db.c \
ft_memdup.c ft_strclen.c ft_strif.c ft_lstaddend_db.c

OBJ=$(SRC:.c=.o)

RM=rm -f

H_PATH=includes/

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@echo "\033[32mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(H_PATH)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[36mCreate libft.a \033[0m"
	@ranlib $(NAME)

clean:
	@echo "\033[31mDelete all \".o\" in libft\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@echo "\033[31mDelete libft.a\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@echo "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) -c $(SRC) -I $(H_PATH)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[36mCreate libft.a \033[0m"
	@ranlib $(NAME)

linux : $(SRC)
	@echo -e "\033[32mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(H_PATH)
	@ar rc $(NAME) $(OBJ)
	@echo -e "\033[36mCreate libft.a \033[0m"
	@ranlib $(NAME)

