#include "philo.h"

void			sprite_init(t_sdl *sdl)
{
	sdl->philo[0] = IMG_LoadTexture(sdl->renderer, "img_src/Cleobule.png");
	sdl->philo[1] = IMG_LoadTexture(sdl->renderer, "img_src/Sade.png");
	sdl->philo[2] = IMG_LoadTexture(sdl->renderer, "img_src/Bacon.png");
	sdl->philo[3] = IMG_LoadTexture(sdl->renderer, "img_src/Grotius.png");
	sdl->philo[4] = IMG_LoadTexture(sdl->renderer, "img_src/Plotin.png");
	sdl->philo[5] = IMG_LoadTexture(sdl->renderer, "./img_src/Vico.png");
	sdl->philo[6] = IMG_LoadTexture(sdl->renderer, "./img_src/Cousin.png");
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
		ft_put_error("Impossible d'initialiser SDL", 2, -1);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	if (TTF_Init() < 0)
		ft_put_error("Impossible d'initialiser SDL TTF", 2, -1);
	if (!Mix_Init(MIX_INIT_MP3))
		ft_put_error("Impossible d'initialiser Mix Init", 2, -1);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		MIX_DEFAULT_CHANNELS, 1024) == -1)
			ft_put_error("Mix_OpenAudio Error", 2, -1);
		Mix_AllocateChannels(3);
	if (TTF_Init() != 0)
		ft_put_error("TTF_Init failed", 2, -1);
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
		if (i % 2 == 0)
			sdl->stru_phi[i]->state = EAT;
		else
			sdl->stru_phi[i]->state = THINK;
		sdl->stru_phi[i]->timer = THINK_T;
		sdl->stru_phi[i]->life = MAX_LIFE;
		sdl->stru_phi[i]->hurt_me = 0;
		i++;
	}
}

void			init_names(t_sdl *sdl)
{
	char **names;
	int i;
	SDL_Color	color;
	SDL_Surface	*surface;

	i = -1;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	names = ft_strsplit("Cleobule Sade Bacon Grotius Plotin Vico Cousin", ' ');
	init_philos(sdl, names);
	while (++i < NB_PHILO)
	{
		surface = TTF_RenderText_Blended(sdl->font,
			sdl->stru_phi[i]->name, color);
		sdl->name_t[i] = SDL_CreateTextureFromSurface(sdl->renderer, surface);
		SDL_FreeSurface(surface);
	}
	i = -1;
	while (++i < NB_PHILO)
		free (names[i]);
	names = NULL;
}

void		init_pos(t_sdl *sdl)
{
	int				i;
	double			angle;

	i = -1;
	angle = 0;
	while (++i < NB_PHILO)
	{
		sdl->pos_philo[i] = create_rect(900 + cos(angle) * 290, 375 + sin(angle) * 290,
			100, 74);
		angle += (double)2 * M_PI / NB_PHILO;
	}
	i = -1;
	while (++i < NB_PHILO)
	{
		sdl->pos_name[i] = create_rect(sdl->pos_philo[i].x,
			sdl->pos_philo[i].y - 30, 0, 0);
	}
}