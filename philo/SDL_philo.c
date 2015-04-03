/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:47:01 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/03 14:04:45 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void 		main_loop(t_sdl *sdl)
{
	int		loop;
	Uint8	*keystate;
	int 	i;

	i = 0;
	loop = 1;
	while (loop)
	{
		while (SDL_PollEvent(&sdl->event))
		{
			keystate = SDL_GetKeyState(NULL);
			SDL_BlitSurface(sdl->table, NULL, sdl->screen,
				&sdl->pos_philo[7]);
			while (i < NB_PHILO)
			{
				SDL_BlitSurface(sdl->philo[i], NULL, sdl->screen,
					&sdl->pos_philo[i]);
				SDL_BlitSurface(sdl->plate[1], NULL, sdl->screen,
					&sdl->pos_plate[i]);
				SDL_BlitSurface(sdl->chop, NULL, sdl->screen,
					&sdl->pos_chop[i]);
				i++;
			}
			SDL_Flip(sdl->screen);
			if (sdl->event.type == SDL_QUIT)
				loop = 0;
			else if (sdl->event.type == SDL_KEYDOWN)
			{
				if (keystate[SDLK_q])
					loop = 0;
			}
			if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
			{
				ft_putnbr(sdl->event.motion.x);
				ft_putendl("");
				ft_putnbr(sdl->event.motion.y);
				ft_putendl("");
			}
		}
	}
}

void		pos_init_plate(t_sdl *sdl)
{/*
324
495
273
376
309
224*/
	sdl->pos_plate[0].x = 448;
	sdl->pos_plate[0].y = 166;
	sdl->pos_plate[1].x = 597;
	sdl->pos_plate[1].y = 251;
	sdl->pos_plate[2].x = 599;
	sdl->pos_plate[2].y = 473;
	sdl->pos_plate[3].x = 462;
	sdl->pos_plate[3].y = 530;
	sdl->pos_plate[4].x = 324;
	sdl->pos_plate[4].y = 495;
	sdl->pos_plate[5].x = 110;
	sdl->pos_plate[5].y = 330;
	sdl->pos_plate[6].x = 180;
	sdl->pos_plate[6].y = 520;
	sdl->pos_plate[7].x = 200;
	sdl->pos_plate[7].y = 110;
}

void		pos_init_chop(t_sdl *sdl)
{
	
	sdl->pos_chop[0].x = 400;
	sdl->pos_chop[0].y = 0;
	sdl->pos_chop[1].x = 670;
	sdl->pos_chop[1].y = 130;
	sdl->pos_chop[2].x = 670;
	sdl->pos_chop[2].y = 450;
	sdl->pos_chop[3].x = 400;
	sdl->pos_chop[3].y = 600;
	sdl->pos_chop[4].x = 160;
	sdl->pos_chop[4].y = 80;
	sdl->pos_chop[5].x = 110;
	sdl->pos_chop[5].y = 330;
	sdl->pos_chop[6].x = 180;
	sdl->pos_chop[6].y = 520;
	sdl->pos_chop[7].x = 200;
	sdl->pos_chop[7].y = 110;
}

void		pos_init(t_sdl *sdl)
{
	int 		i;

	i = 0;
	sdl->pos_philo[0].x = 400;
	sdl->pos_philo[0].y = 0;
	sdl->pos_philo[1].x = 670;
	sdl->pos_philo[1].y = 130;
	sdl->pos_philo[2].x = 670;
	sdl->pos_philo[2].y = 450;
	sdl->pos_philo[3].x = 400;
	sdl->pos_philo[3].y = 600;
	sdl->pos_philo[4].x = 160;
	sdl->pos_philo[4].y = 80;
	sdl->pos_philo[5].x = 110;
	sdl->pos_philo[5].y = 330;
	sdl->pos_philo[6].x = 180;
	sdl->pos_philo[6].y = 520;
	sdl->pos_philo[7].x = 200;
	sdl->pos_philo[7].y = 110;
	pos_init_plate(sdl);
	pos_init_chop(sdl);
}

void		sprite_init(t_sdl *sdl)
{
	sdl->philo[2] = IMG_Load("img_src/Bacon.png");
	sdl->philo[0] = IMG_Load("img_src/Cleobule.png");
	sdl->philo[6] = IMG_Load("img_src/Cousin.png");
	sdl->philo[3] = IMG_Load("img_src/Grotius.png");
	sdl->philo[4] = IMG_Load("img_src/Plotin.png");
	sdl->philo[1] = IMG_Load("img_src/Sade.png");
	sdl->philo[5] = IMG_Load("img_src/Vico.png");
	sdl->table = IMG_Load("img_src/table.png");
	sdl->plate[0] = IMG_Load("img_src/assiettepleine.png");
	sdl->plate[1] = IMG_Load("img_src/assiettevide.png");
	sdl->chop = IMG_Load("img_src/baguette.png");
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)**av;
	t_sdl		sdl;

	if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) == -1)
	{
		ft_putendl_fd("Error : cannot initialize SDL, program abort", 2);
		exit (-1);
	}
	sdl.screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN,
		COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if ((TTF_Init()) == -1)
		ft_putendl_fd("Error : Cannot load SDL_ttf", 2);
	if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0)
		ft_putendl_fd("Error : Cannot load music", 2);
	if (sdl.screen == NULL)
		ft_putendl_fd("Error : Cannot load video", 2);
	SDL_WM_SetCaption("Philosophers", NULL);
	sprite_init(&sdl);
	pos_init(&sdl);
	main_loop(&sdl);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	//penser a liberer toutes les surfaces
	return (0);
}
