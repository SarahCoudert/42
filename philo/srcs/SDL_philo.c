/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:47:01 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/23 13:26:43 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <unistd.h>

/*
** g_time = TIMEOUT (temps avant fin)
** time_now = temps qui s'est deroule depuis le debut (time() == epoch) pris
** au debut de la boucle
** time_since = temps qui s'est ecoule depuis le debut mais pris a la fin de
** la boucle
*/

SDL_Rect		create_rect(int x, int y, int h, int w)
{
	SDL_Rect		rect;

	rect.x = x;
	rect.y = y;
	rect.h = h;
	rect.w = w;
	return (rect);
}

int			event(t_sdl *sdl)
{
	int			continuer;
	int			res;
	int			son;

	son = 1;
	res = 0;
	continuer = 1;
	sprite_init(sdl);
	init_names(sdl);
	Mix_PlayMusic(sdl->music[0], -1);
	sdl_renderall(sdl);
	SDL_RenderPresent(sdl->renderer);
	usleep(1000000);
	while (continuer)
	{
		SDL_PollEvent(&sdl->event);
		if (sdl->event.window.event == SDL_WINDOWEVENT_CLOSE)
			return (-1);
		if (sdl->event.type == SDL_KEYDOWN)
		{
			sound(sdl, &son);
		}
		res = timer();
		if (res == 1)
		{
			sdl_renderall(sdl);
			SDL_RenderPresent(sdl->renderer);
		}
		else if (res == -1)
			continuer = 0;
	}
	return (0);
}

int				timer()
{
	static int	time_now = 0;
	static int	time_since = 0;

	time_now = time(NULL);
	if (time_now != time_since && g_time > 0)
	{
		g_time--;
		time_since = time_now;
		return (1);
	}
	else if (g_time <= 0)
		return (-1);
	else
		usleep(10000);
	return (0);
}

int				main(int ac, char **av)
{
	t_sdl		sdl;
	g_time = TIMEOUT;

	(void)ac;
	(void)**av;
	init_all(&sdl);
	sdl.font = TTF_OpenFont("./font/Quicksand.ttf", 25);
	sdl.font_e = TTF_OpenFont("./font/Ohi.ttf", 70);
	sdl.font_m = TTF_OpenFont("./font/cartoon.ttf", 60);
	if (sdl.screen == NULL)
	{
		ft_putendl_fd("Screen problem", 2);
		return (-1);
	}
	sdl.renderer = SDL_CreateRenderer(sdl.screen, -1, 0);
	menu(&sdl);
	if (event(&sdl) == 0)
		end(&sdl);
	cleanup(&sdl);
	return (0);
}
