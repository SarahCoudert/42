# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/13 14:48:43 by scoudert          #+#    #+#              #
#    Updated: 2015/04/02 16:36:11 by scoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror

NAME=philo

CC=gcc

SRC=SDL_philo.c

INCLUDES= -I ./libft/includes/ -I ./includes/ \
		  -I ~/Library/frameworks/SDL.framework/Headers/ \
		 -I ~/Library/frameworks/SDL_ttf.framework/Headers/ \
		 -I ~/Library/frameworks/SDL_mixer.framework/Headers/ \
		 -I ~/Library/frameworks/SDL_image.framework/Headers/ \


LIBS = -L ./libft -lft -L /usr/lib -lm

SDL = -framework SDL -F ~/Library/frameworks \
	  -framework SDL_ttf -F ~/Library/frameworks/ \
	  -framework SDL_mixer -F ~/Library/frameworks/ \
	  -framework SDL_image -F ~/Library/frameworks


OBJ=$(SRC:.c=.o)

RM=rm -f

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	@$(CC) $(INCLUDES) $(OBJ) $(SDL) $(LIBS) -o $(NAME) -lpthread

$(OBJ): $(SRC)
	@make -C ./libft/
	@$(CC) $(INCLUDES) -c $(SRC)
	#@gcc $(FLAGS) $(INCLUDES) -c $(SRC)

clean:
	@make -C libft/ clean
	@echo "\033[31mDelete all \".o\" in philo\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@echo "\033[31mDelete philo executable\033[0m"
	@$(RM) $(NAME)

re: fclean all
