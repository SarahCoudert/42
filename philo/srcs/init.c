#include "philo.h"

void			sprite_init(t_sdl *sdl)
{
	sdl->philo[0] = IMG_LoadTexture(sdl->renderer, "img_src/Cleobule.png");
	sdl->philo[1] = IMG_LoadTexture(sdl->renderer, "img_src/Sade.png");
	sdl->philo[2] = IMG_LoadTexture(sdl->renderer, "img_src/Bacon.png");
	sdl->philo[3] = IMG_LoadTexture(sdl->renderer, "img_src/Grotius.png");
	sdl->philo[4] = IMG_LoadTexture(sdl->renderer, "img_src/Plotin.png");
	sdl->philo[5] = IMG_LoadTexture(sdl->renderer, "img_src/Vico.png");
	sdl->philo[6] = IMG_LoadTexture(sdl->renderer, "img_src/Cousin.png");
	sdl->plate[0] = IMG_LoadTexture(sdl->renderer,
		"img_src/assiettepleine.png");
	sdl->plate[1] = IMG_LoadTexture(sdl->renderer,
		"img_src/assiettevide.png");
	sdl->table = IMG_LoadTexture(sdl->renderer, "img_src/table.png");
	sdl->chop[0] = IMG_LoadTexture(sdl->renderer,
		"img_src/baguette.png");
	sdl->chop[1] = IMG_LoadTexture(sdl->renderer,
		"img_src/baguettehorizon.png");
}

void			init_all(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_putendl_fd("Impossible d'initialiser SDL", 2);
		exit (-1);
	}
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	if (TTF_Init() < 0)
	{
		ft_putendl_fd("Impossible d'initialiser SDL TTF", 2);
		exit(1);
	}
	if (!Mix_Init(MIX_INIT_MP3))
	{
		ft_putendl_fd("Impossible d'initialiser Mix Init", 2);
		exit(1);
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		ft_putendl_fd("Mix Open Audio failed", 2);
		exit(1);
	}
	if (TTF_Init() != 0)
	{
		ft_putendl_fd("TTF_Init failed", 2);
		exit(1);
	}
	sdl->screen = SDL_CreateWindow("Philosopher's Dinner",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIDTH_SCREEN, HEIGHT_SCREEN, 0);
}

void			init_philos(t_sdl *sdl, char **names)
{
	int		i;

	i = 0;
	while (i < NB_PHILO)
	{
		sdl->stru_phi[i] = (t_philo*)malloc(sizeof(t_philo));
		sdl->stru_phi[i]->which = i;
		sdl->stru_phi[i]->name = names[i];
		sdl->stru_phi[i]->state = THINK;
		sdl->stru_phi[i]->timer = THINK_T;
		sdl->stru_phi[i]->life = MAX_LIFE;
		sdl->stru_phi[i]->hurt_me = 0;
		i++;
	}
}

void			init_names_c(t_sdl *sdl)
{
	char **names;
	int i;

	i = -1;
	names = (char**)malloc(7 * sizeof (char*));
	names[0] = ft_strdup("Cleobule");
	names[1] = ft_strdup("Sade");
	names[2] = ft_strdup("Bacon");
	names[3] = ft_strdup("Grotius");
	names[4] = ft_strdup("Plotin");
	names[5] = ft_strdup("Vico");
	names[6] = ft_strdup("Cousin");
	init_philos(sdl, names);
}

void			init_names_t(t_sdl *sdl)
{
	TTF_Font	*openfont;
	SDL_Color	color;
	SDL_Surface	*surface;
	int			i;

	i = 0;
	color.r = 255;
	color.g = 255;
	color.b = 255;
		openfont = TTF_OpenFont("/nfs/zfs-student-3/users/2014_paris/scoudert/code/philo/srcs/Quicksand-Regular.ttf", 30);
	while (i < NB_PHILO)
	{
		surface = TTF_RenderText_Solid(openfont, sdl->stru_phi[i]->name,
			color);
		sdl->name_t[i] = SDL_CreateTextureFromSurface(sdl->renderer, surface);
		i++;
	}
	TTF_CloseFont(openfont);
}