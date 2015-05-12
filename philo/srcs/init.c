/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:32:08 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/05 14:32:12 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	sdl->plate[1] = IMG_LoadTexture(sdl->renderer, "img_src/assiettevide.png");
	sdl->table = IMG_LoadTexture(sdl->renderer, "img_src/table.png");
	sdl->chop[0] = IMG_LoadTexture(sdl->renderer, "img_src/baguette.png");
	sdl->chop[1] = IMG_LoadTexture(sdl->renderer,
		"img_src/baguettehorizon.png");
	sdl->state[0] = IMG_LoadTexture(sdl->renderer, "img_src/sleep.png");
	sdl->state[1] = IMG_LoadTexture(sdl->renderer, "img_src/think.png");
	sdl->state[2] = IMG_LoadTexture(sdl->renderer, "img_src/other.png");
	sdl->state[3] = IMG_LoadTexture(sdl->renderer, "img_src/dead.png");
	sdl->font = TTF_OpenFont("./font/Quicksand.ttf", 25);
	sdl->font_e = TTF_OpenFont("./font/Ohi.ttf", 60);
	sdl->font_m = TTF_OpenFont("./font/cartoon.ttf", 60);
}

void			init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_put_error("Impossible d'initialiser SDL", 2, -1);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	if (TTF_Init() < 0)
		ft_put_error("Impossible d'initialiser SDL TTF", 2, -1);
	Mix_Init(MIX_INIT_MP3);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		MIX_DEFAULT_CHANNELS, 1024) == -1)
		ft_put_error("Mix_OpenAudio Error", 2, -1);
	Mix_AllocateChannels(5);
	sdl->screen = SDL_CreateWindow("Philosopher's Dinner",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIDTH_SCREEN, HEIGHT_SCREEN, 0);
}

void			init_philos(t_sdl *sdl, char **names)
{
	int			i;

	i = 0;
	while (i < NB_PHILO)
	{
		sdl->stru_phi[i] = (t_philo*)malloc(sizeof(t_philo));
		pthread_mutex_init(&g_glo->g_mut_chop[i], NULL);
		sdl->stru_phi[i]->which = i;
		sdl->stru_phi[i]->name = names[i];
		sdl->stru_phi[i]->state = THINK;
		sdl->stru_phi[i]->timer = 0;
		g_glo->life[i] = MAX_LIFE;
		sdl->stru_phi[i]->life = MAX_LIFE;
		sdl->stru_phi[i]->can_eat = 1;
		sdl->stru_phi[i]->hurt_me = 0;
		pthread_create(&(sdl->stru_phi[i])->thread, NULL, fn_phi,
			(void*)sdl->stru_phi[i]);
		g_glo->g_bool_chop[i] = 0;
		i++;
	}
}

void			init_names(t_sdl *sdl)
{
	char		**names;
	int			i;
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
	}
	i = -1;
	while (++i < NB_PHILO)
		free (names[i]);
	names = NULL;
}

void			init_pos(t_sdl *sdl)
{
	int			i;
	double		angle;

	i = -1;
	angle = 0;
	while (++i < NB_PHILO)
	{
		sdl->pos_philo[i] = create_rect(900 + cos(angle) * 290,
		375 + sin(angle) * 290, 100, 74);
		angle += (double)2 * M_PI / NB_PHILO;
	}
	i = -1;
	while (++i < NB_PHILO)
	{
		sdl->pos_name[i] = create_rect(sdl->pos_philo[i].x,
			sdl->pos_philo[i].y - 30, 0, 0);
		sdl->pos_state[i] = create_rect(sdl->pos_philo[i].x - 60,
			sdl->pos_philo[i].y - 30, 0, 0);
	}
}
