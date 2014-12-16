# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 17:46:31 by mgrimald          #+#    #+#              #
#    Updated: 2014/12/08 17:20:18 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DIR = includes

SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c  \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstadd.c \
	  ft_lstnew.c \
	  ft_lstmap.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstadd_db.c \
	  ft_strrev.c \
	  ft_strclen.c \
	  ft_memdup.c \
	  ft_lstnew_db.c \
	  ft_lstlen_db.c \
	  ft_lstlen.c \
	  ft_lstgo_n_prev.c \
	  ft_lstgo_n_next.c \
	  ft_lstgetstart_db.c \
	  ft_lstgetend_db.c \
	  ft_lstdelone_db.c \
	  ft_lstdel_db.c \
	  ft_lstdelall_db.c \
	  ft_lsttochar_db.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;36m[Compile all \".o\"]\033[0m"
	@ar rc $(NAME) $(OBJ)
	@echo "\033[1;34m[Create libft.a]\033[0m"
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@echo "\033[1;36m[Compile all \".c\"]\033[0m"
	@$(CC) $(FLAGS) -I $(DIR) -c $(SRC)

clean:
	@echo "\033[1;31m[Delete all \".o\"]\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[1;31m[Delete libft.a]\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
