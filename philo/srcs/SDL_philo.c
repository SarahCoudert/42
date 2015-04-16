/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:47:01 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/16 18:00:11 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"
#include <unistd.h>

SDL_Rect	create_rect(int x, int y, int h, int w)
{
	SDL_Rect		rect;

	rect.x = x;
	rect.y = y;
	rect.h = h;
	rect.w = w;
	return (rect);
}

void				render_philo(t_sdl *sdl)
{
	SDL_Rect		pos;
	int				i;
	double			angle;
	SDL_Texture		*texture;

	i = -1;
	angle = 0;
	while (++i < NB_PHILO)
	{
		texture = sdl->philo[i];
		pos = create_rect(640 + cos(angle) * 280, 360 + sin(angle) * 280,
			100, 74);
		angle += (double)2 * M_PI / NB_PHILO;
		SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	}
}

void				render_chops(t_sdl *sdl)
{
	SDL_Rect		pos;
	int				i;
	double			angle;
	SDL_Texture		*tex;

	i = 0;
	angle = 5.8;
	SDL_QueryTexture(sdl->chop[0], NULL, NULL, &pos.w, &pos.h);
	while (i < NB_PHILO)
	{
		tex = sdl->chop[0];
		pos = create_rect(640 + cos(angle) * 220, 360 + sin(angle) * 220,
			pos.w, pos.h);
		angle += (double)(2 * M_PI / 7);
		SDL_RenderCopy(sdl->renderer, tex, NULL, &pos);
		i++;
	}
}

void				render_table(t_sdl *sdl)
{
	SDL_Rect		pos;

	SDL_QueryTexture(sdl->table, NULL, NULL, &pos.w, &pos.h);
	pos = create_rect(440, 210, pos.w, pos.h);
	SDL_RenderCopy(sdl->renderer, sdl->table, NULL, &pos);
}

void		sprite_init(t_sdl *sdl)
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
		"img_src/baguetteverti.png");
	sdl->chop[1] = IMG_LoadTexture(sdl->renderer,
		"img_src/baguettehorizon.png");
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)**av;
	t_sdl		sdl;
	int continuer;

	continuer = 1;
	if (SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
	{
		printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
		return EXIT_FAILURE;
	}
	IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
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
	sdl.screen = SDL_CreateWindow("Philosopher's Dinner" ,
		SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED,
		WIDTH_SCREEN, HEIGHT_SCREEN, 0);
		if (sdl.screen == NULL)
		{
			ft_putendl_fd("Screen problem", 2);
			return EXIT_FAILURE;
		}
	sdl.renderer = SDL_CreateRenderer(sdl.screen, -1, 0);
	sprite_init(&sdl);
	ft_putendl("Sprite init done");
	while (continuer)
	{
		while (SDL_PollEvent(&sdl.event))
		{
			if(sdl.event.window.event == SDL_WINDOWEVENT_CLOSE)
				continuer = 0;
		}
		SDL_SetRenderDrawColor(sdl.renderer, 80, 80, 80, 255);
		SDL_RenderClear(sdl.renderer);
		render_philo(&sdl);
		render_table(&sdl);
		render_chops(&sdl);
		SDL_RenderPresent(sdl.renderer);
	}
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	//penser a liberer toutes les surfaces
	return (0);
}
