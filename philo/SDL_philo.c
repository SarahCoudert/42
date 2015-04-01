/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:47:01 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/01 18:38:53 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void 		main_loop(t_sdl *sdl)
{
	int		loop;
//	Uint8	*keystate;
	int 	i;

	i = 0;
	loop = 1;
	while (loop)
	{
		while (SDL_PollEvent(&sdl->event))
		{
			while (i < NB_PHILO)
			{
				SDL_BlitSurface(sdl->philo[i], NULL, sdl->screen,
					&sdl->pos_philo[7]);
			}
			SDL_Flip(sdl->screen);
			if (sdl->event.type == SDL_QUIT)
				loop = 0;
		}
	}
}

void 		pos_init(t_sdl *sdl)
{
	sdl->pos_philo[0].x = 20;
	sdl->pos_philo[0].y = 20;
	sdl->pos_philo[1].x = 50;
	sdl->pos_philo[1].y = 50;
	sdl->pos_philo[2].x = 70;
	sdl->pos_philo[2].y = 70;
	sdl->pos_philo[3].x = 90;
	sdl->pos_philo[3].y = 90;
	sdl->pos_philo[4].x = 110;
	sdl->pos_philo[4].y = 110;
	sdl->pos_philo[5].x = 130;
	sdl->pos_philo[5].y = 130;
	sdl->pos_philo[6].x = 150;
	sdl->pos_philo[6].y = 150;
	sdl->pos_philo[7].x = WIDTH_SCREEN / 2;
	sdl->pos_philo[7].y = HEIGHT_SCREEN / 2;
}

void		sprite_init(t_sdl *sdl)
{
	sdl->philo[0] = IMG_Load("img_src/Bacon.jpg");
	sdl->philo[1] = IMG_Load("img_src/Cleobule.jpg");
	sdl->philo[2] = IMG_Load("img_src/Cousin.jpg");
	sdl->philo[3] = IMG_Load("img_src/Grotius.jpg");
	sdl->philo[4] = IMG_Load("img_src/Plotin.jpg");
	sdl->philo[5] = IMG_Load("img_src/Sade.jpg");
	sdl->philo[6] = IMG_Load("img_src/Vico.jpg");
	sdl->philo[7] = IMG_Load("img_src/baguette.png");
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_sdl		sdl;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
	{
		ft_putendl_fd("Error : cannot initialize SDL, program abort", 2);
		exit (-1);
	}
	sdl.screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN,
		COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (TTF_Init() == -1)
		ft_putendl_fd("Error : Cannot load SDL_ttf", 2);
	if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0)
		ft_putendl_fd("Error : Cannot load music", 2);
	if (sdl.screen == NULL)
		ft_putendl_fd("Error : Cannot load video", 2);
	SDL_WM_SetCaption("Philosophers", NULL);
	sprite_init(&sdl);
	pos_init(&sdl);
	main_loop(&sdl);
	return (0);
}
