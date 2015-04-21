NAME = philo
CC = gcc
FLAGS = -Wall -Werror -Wextra
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	INCLUDES = -I ./includes/ -I /usr/includes/
	SDL = -L /usr/lib -lSDL2 -lSDL2_ttf -lSDL2_mixer
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
SRCS = SDL_philo.c display.c init.c display2.c clean.c menu.c
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
	@$(CC) $(FLAGS) $(INCLUDES) -c $(SRC)
	@mkdir -p $(OBJS_D)
	@mv $(OBJS) $(OBJS_D)

debug: $(OBJ)
	@$(CC) $(FLAGS) -g $(INCLUDES) $(OBJ) $(SDL) $(LIBS) -o $(NAME) -lpthread

clean:
	@make clean -C ./libft/
	@rm -rf $(OBJS_D)

fclean: clean
	@make fclean -C ./libft/
	@rm -f $(NAME)

re: fclean all
