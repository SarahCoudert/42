# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/20 15:03:25 by aiwanesk          #+#    #+#              #
#    Updated: 2015/05/20 15:03:26 by aiwanesk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
FLAGS = -Wall -Werror -Wextra
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	INCLUDES = -I ./includes/ -I /usr/includes/
	SDL = -L /usr/lib -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image
else
	INCLUDES = -I ./includes/ -I ./frameworks/SDL2.framework/Headers \
			   -I ./frameworks/SDL2_ttf.framework/Headers \
			   -I ./frameworks/SDL2_mixer.framework/Headers/ \
			   -I ./Frameworks/SDL2_image.framework/Headers/
	SDL = -framework SDL2 -F ./frameworks/ \
		  -framework SDL2_ttf -F ./frameworks/ \
		  -framework SDL2_mixer -F ./frameworks \
		  -framework SDL2_image -F ./frameworks \

endif
LIBS = -L ./libft -lft -L /usr/lib -lm

SRC_D = srcs

OBJS_D = objs

SRCS = sdl_main.c display.c init.c display2.c clean.c end_n_sound.c \
	color.c display3.c philo2.c main.c menu.c

OBJS = $(SRCS:.c=.o)

SRC		:=	$(addprefix $(SRC_D)/, $(SRCS))
OBJ		:=	$(addprefix $(OBJS_D)/, $(OBJS))

.PHONY: all debug clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32mCreate philo executable\033[0m"
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJ) $(SDL) $(LIBS) -o $(NAME) -lpthread

$(OBJ): $(SRC)
	@make -C ./libft/
	@$(CC) -g $(FLAGS) $(INCLUDES) -c $(SRC)
	@mkdir -p $(OBJS_D)
	@mv $(OBJS) $(OBJS_D)

debug: $(OBJ)
	@make -C libft/ debug
	@$(CC) -g $(FLAGS) $(INCLUDES) $(OBJ) $(SDL) $(LIBS) -o $(NAME) -lpthread

clean:
	@make clean -C ./libft/
	@rm -rf $(OBJS_D)

fclean: clean
	@make fclean -C ./libft/
	@rm -f $(NAME)

install_sdl :
	@echo "\033[32mInstalling Frameworks/SDL2 in ~/Library/\033[0m"
	if [ -a ~/Library/Frameworks/ ] ; \
	then  \
		cp -r ./Frameworks/* ~/Library/Frameworks/ ; \
	else \
		cp -r ./Frameworks ~/Library/ ; \
	fi; 

re: fclean all
