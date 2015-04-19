/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:47:01 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/19 16:07:31 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <unistd.h>

int			g_time;


void cleanup(t_sdl *sdl)
{
	Mix_CloseAudio();
	Mix_Quit();
	SDL_DestroyRenderer(sdl->renderer);
	sdl->renderer = NULL;
	SDL_DestroyWindow(sdl->screen);
	sdl->screen = NULL;
	TTF_Quit();
	SDL_Quit();
	return ;
}

SDL_Rect		create_rect(int x, int y, int h, int w)
{
	SDL_Rect		rect;

	rect.x = x;
	rect.y = y;
	rect.h = h;
	rect.w = w;
	return (rect);
}

void		*timer(void *p_data)
{
	int		time_now;
	int		time_since;

	time_now = time(NULL);
	(void)p_data;
	while (g_time > 0)
	{
		time_since = time(NULL);
		if (time_now != time_since)
		{
			g_time--;
			time_now = time_since;
		}
		usleep(10000);
	}
	return (NULL);
}

int				main(int ac, char **av)
{
	t_sdl		sdl;
	int			continuer;
//	pthread_t	timer_t;
	int time_now;

	g_time = TIMEOUT;
	time_now = TIMEOUT;
	(void)ac;
	(void)**av;
	continuer = 1;
	init_all(&sdl);
//	pthread_create(&timer_t, NULL, timer, NULL);
	if (sdl.screen == NULL)
	{
		ft_putendl_fd("Screen problem", 2);
		return (-1);
	}
	sdl.renderer = SDL_CreateRenderer(sdl.screen, -1, 0);
	sprite_init(&sdl);
	ft_putendl("Sprite init done");
//	pthread_join(timer_t, NULL);
	while (continuer)
	{
		while (SDL_PollEvent(&sdl.event))
		{
			if (sdl.event.window.event == SDL_WINDOWEVENT_CLOSE)
				return (0);
								sdl_renderall(&sdl);

			/*if (g_time > 0)
			{
				if (time_now > g_time)
				{
					time_now = g_time;
				}
				else
					usleep(10000);
			}
			else
				return (0);*/
		}
	}
	cleanup(&sdl);
	return (0);
}
