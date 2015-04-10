/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:47:01 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/10 19:01:14 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
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
				&sdl->pos_table);
			while (i < NB_PHILO)
			{
				SDL_BlitSurface(sdl->philo[i], NULL, sdl->screen,
					&sdl->pos_philo[i]);
				SDL_BlitSurface(sdl->plate[1], NULL, sdl->screen,
					&sdl->pos_plate[i]);
				if (i == 0 || i == 3)
					SDL_BlitSurface(sdl->chop[0], NULL, sdl->screen,
						&sdl->pos_chop[i]);
				else
					SDL_BlitSurface(sdl->chop[1], NULL, sdl->screen,
						&sdl->pos_chop[i]);
				i++;
			}
			i = 0;
			SDL_Flip(sdl->screen);
			if (sdl->event.type == SDL_QUIT)
				loop = 0;
			else if (sdl->event.type == SDL_KEYDOWN)
			{
				if (keystate[SDLK_q])
					loop = 0;
			}
		}
	}
}

void		pos_init_plate(t_sdl *sdl)
{
	sdl->pos_plate[0].x = 1000;
	sdl->pos_plate[0].y = 220;

	sdl->pos_plate[1].x = 1160;//haut droite
	sdl->pos_plate[1].y = 300;

	sdl->pos_plate[2].x = 1170;//bas droite
	sdl->pos_plate[2].y = 503;

	sdl->pos_plate[3].x = 1040;//bas milieu
	sdl->pos_plate[3].y = 602;

	sdl->pos_plate[4].x = 875;
	sdl->pos_plate[4].y = 543;//bas gauche

	sdl->pos_plate[5].x = 816; //gauche milieu
	sdl->pos_plate[5].y = 420;

	sdl->pos_plate[6].x = 860;//haut gauche  
	sdl->pos_plate[6].y = 280;
}

void		pos_init_chop(t_sdl *sdl)
{
	
	sdl->pos_chop[0].x = 1090;
	sdl->pos_chop[0].y = 250;

	sdl->pos_chop[1].x = 1225;
	sdl->pos_chop[1].y = 375;

	sdl->pos_chop[2].x = 1150;
	sdl->pos_chop[2].y = 580;

	sdl->pos_chop[3].x = 1040;
	sdl->pos_chop[3].y = 630;

	sdl->pos_chop[4].x = 930;
	sdl->pos_chop[4].y = 533;

	sdl->pos_chop[5].x = 806;
	sdl->pos_chop[5].y = 462;

	sdl->pos_chop[6].x = 940;
	sdl->pos_chop[6].y = 370;
}

void		pos_init(t_sdl *sdl)
{
	sdl->pos_philo[0].x = 1000;
	sdl->pos_philo[0].y = 100; // haut milieu

	sdl->pos_philo[1].x = 1290; //haut droite
	sdl->pos_philo[1].y = 250;
	
	sdl->pos_philo[2].x = 1280;
	sdl->pos_philo[2].y = 550; //bas droite 
	
	sdl->pos_philo[3].x = 1040; //nas milieu
	sdl->pos_philo[3].y = 710;
	
	sdl->pos_philo[4].x = 760;//haut gauche
	sdl->pos_philo[4].y = 180;
	
	sdl->pos_philo[5].x = 710; //gauche
	sdl->pos_philo[5].y = 420;
	
	sdl->pos_philo[6].x = 780; //bas gauche
	sdl->pos_philo[6].y = 630;
	
	sdl->pos_table.x = 800;
	sdl->pos_table.y = 210;
	pos_init_plate(sdl);
	pos_init_chop(sdl);
}

void		sprite_init(t_sdl *sdl)
{
	sdl->philo[0] = IMG_Load("img_src/Cleobule.png");
	sdl->philo[1] = IMG_Load("img_src/Sade.png");
	sdl->philo[2] = IMG_Load("img_src/Bacon.png");
	sdl->philo[3] = IMG_Load("img_src/Grotius.png");
	sdl->philo[4] = IMG_Load("img_src/Plotin.png");
	sdl->philo[5] = IMG_Load("img_src/Vico.png");
	sdl->philo[6] = IMG_Load("img_src/Cousin.png");

	sdl->plate[0] = IMG_Load("img_src/assiettepleine.png");
	sdl->plate[1] = IMG_Load("img_src/assiettevide.png");

	sdl->table = IMG_Load("img_src/table.png");

	sdl->chop[0] = IMG_Load("img_src/baguetteverti.png");
	sdl->chop[1] = IMG_Load("img_src/baguettehorizon.png");
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)**av;
	t_sdl		sdl;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Quit();
		return -1;
	}
	sdl.screen = SDL_CreateWindow("Philosopher's dinner", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH_SCREEN, HEIGHT_SCREEN, SDL_WINDOW_SHOWN);
	if (!sdl.screen)
	{
		SDL_Quit();
		return (-1);
	}
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
