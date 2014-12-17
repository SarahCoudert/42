# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 16:10:00 by scoudert          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2014/12/08 14:40:21 by scoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
=======
#    Updated: 2014/11/18 15:07:05 by scoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85

CC=gcc

CFLAGS=-Wall -Wextra -Werror

<<<<<<< HEAD
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
ft_lstcountbytes.c ft_putnbr.c ft_strlen.c ft_strnstr.c ft_tolower.c \
ft_isprint.c tabmerge_sort.c

OBJ=$(SRC:.c=.o)

RM=rm -f
=======
PATH=includes/

SRC=ft_lstdel.c \
	ft_memdel.c \
	ft_putnbr_fd.c \
	ft_strdel.c \
	ft_strmap.c \
	ft_strrchr.c \
	ft_toupper.c \
	ft_atoi.c\
	ft_lstdelone.c \
	ft_memmove.c \
	ft_putstr.c \
	ft_strdup.c\
	ft_strmapi.c\
	ft_strrev.c \
	ft_bzero.c \
	ft_lstnew.c \
	ft_memset.c \
	ft_putstr_fd.c \
	ft_strequ.c \
	ft_strncat.c \
	ft_strsplit.c \
	ft_isalnum.c \
	ft_memalloc.c \
	ft_putchar.c \
	ft_strcat.c \
	ft_striter.c \
	ft_strncmp.c \
	ft_strstr.c\
	ft_isalpha.c \
	ft_memccpy.c \
	ft_putchar_fd.c \
	ft_strchr.c \
	ft_striteri.c \
	ft_strncpy.c \
	ft_strsub.c \
	ft_isascii.c \
	ft_memchr.c \
	ft_putendl.c \
	ft_strclr.c\
	ft_strjoin.c \
	ft_strnequ.c \
	ft_strtrim.c \
	ft_isdigit.c \
	ft_memcmp.c \
	ft_putendl_fd.c \
	ft_strcmp.c \
	ft_strlcat.c \
	ft_strnew.c \
	ft_swap.c \
	ft_lstcountelements.c \
	ft_lstcountbytes.c \
	tabmerge_sort.c \
	
OBJ= $(SRC:.c=.o)

RM= rm -f
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85

.PHONY: all, clean, fclean, re

all:
<<<<<<< HEAD
	@make $(NAME)

$(NAME):
	@echo "\033[36mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[36mCreate libft.a \033[0m"
	@ranlib $(NAME)

clean:
	@echo "\033[36mDelete all \".o\"\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@echo "\033[36mDelete libft.a\033[0m"
	@$(RM) $(NAME)
=======
	make $(NAME)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -I $(PATH) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85

re: fclean all
