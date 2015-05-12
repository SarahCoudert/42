/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:47:01 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/05 14:31:32 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void			init_all(t_sdl *sdl)
{
	init_sdl(sdl);
	sprite_init(sdl);
	init_names(sdl);
	init_pos(sdl);
	init_sound(sdl);
}

SDL_Rect		create_rect(int x, int y, int h, int w)
{
	SDL_Rect	rect;

	rect.x = x;
	rect.y = y;
	rect.h = h;
	rect.w = w;
	return (rect);
}

int				event(t_sdl *sdl)
{
	int			continuer;
	int			son;
	int		time_now;

	time_now = TIMEOUT;
	son = 1;
	continuer = 1;
	Mix_PlayMusic(sdl->music[0], -1);
	sdl_renderall(sdl);
	usleep(100000);
	while (continuer)
	{
		SDL_PollEvent(&sdl->event);
		if (sdl->event.window.event == SDL_WINDOWEVENT_CLOSE)
			return (-1);
		if (sdl->event.type == SDL_KEYDOWN)
			sound(sdl, &son);
		if (time_now > g_glo->g_time)
		{
			time_now = g_glo->g_time;
			sdl_renderall(sdl);
		}
		else
			usleep (10000);
		if (g_glo->g_time <= 0)
			continuer = 0;
	}
	return (0);
}

void				*main_2(void *p_data)
{
	t_sdl		*sdl;

	g_glo->g_time = TIMEOUT;
	sdl = (t_sdl*)p_data;
	if (sdl->screen == NULL)
	{
		ft_putendl_fd("Screen problem", 2);
		return (NULL);
	}
	sdl->renderer = SDL_CreateRenderer(sdl->screen, -1, 0);
	if (event(sdl) == 0)
		end(sdl, 1);
	cleanup(sdl);
	return (NULL);
}
