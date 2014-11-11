NAME = libft
SRC = ft_atoi.c ft_isascii.c ft_memchr.c ft_putchar.c ft_strchr.c ft_strlcat.c\
	  ft_strncpy.c ft_tolower.c main.c ft_bzero.c ft_isdigit.c ft_memcpy.c\
	  ft_putnbr.c ft_strcmp.c ft_strlen.c ft_strnstr.c ft_toupper.c \
	  ft_isalnum.c ft_isprint.c ft_memmove.c ft_putstr.c ft_strcpy.c\
	  ft_strncat.c ft_strrchr.c libft.h ft_isalpha.c ft_memccpy.c ft_memset.c\
	  ft_strcat.c ft_strdup.c ft_strncmp.c ft_strstr.c
OBJ = $(FTC:.c =.o))
SRC_H = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -c $(SRC) $(SRC_H) $(CFLAGS)$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
