# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/13 14:48:43 by scoudert          #+#    #+#              #
#    Updated: 2015/03/10 16:39:59 by scoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror

DEBUG =$(CFLAGS) -g

NAME=ft_ls

CC=gcc

SRC=main.c ls_simple.c t_lsfunctions.c l_opt.c error.c

HEADER=libft/includes

OBJ=$(SRC:.c=.o)

RM=rm -f

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@make -C libft/
	@echo "\033[32mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[36mCreate $(NAME)\033[0m"

clean:
	@make -C libft/ clean
	@echo "\033[31mDelete all \".o\" in ft_ls\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@echo "\033[31mDelete ft_ls executable\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@make -C libft/ fclean
	@make -C libft/ debug
	@echo "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) -c $(SRC) -I $(HEADER)
	@$(CC) $(DEBUG) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[36mCreate $(NAME) with debug flag\033[0m"

linux : $(SRC)
	@make -C libft/ linux
	@echo -e "\033[32mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo -e "\033[36mCreate $(NAME)\033[0m"

