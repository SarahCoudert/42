/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 14:13:57 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/05/14 14:13:59 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void		init_all(t_sdl *sdl)
{
	init_sdl(sdl);
	init_color(sdl);
	sprite_init(sdl);
	init_names(sdl);
	init_pos(sdl);
	init_sound(sdl);
}

SDL_Rect	create_rect(int x, int y, int h, int w)
{
	SDL_Rect	rect;

	rect.x = x;
	rect.y = y;
	rect.h = h;
	rect.w = w;
	return (rect);
}

void		init_begin(t_sdl *sdl)
{
	char	**names;
	int		i;

	i = -1;
	names = ft_strsplit("Cleobule Sade Bacon Grotius Plotin Vico Cousin", ' ');
	while (++i < NB_PHILO)
	{
		sdl->stru_phi[i] = (t_philo*)malloc(sizeof(t_philo));
		pthread_mutex_init(&g_glo->g_mut_chop[i], NULL);
		sdl->stru_phi[i]->which = i;
		sdl->stru_phi[i]->name = names[i];
		sdl->stru_phi[i]->state = THINK;
		g_glo->state[i] = THINK;
		sdl->stru_phi[i]->timer = 0;
		g_glo->life[i] = MAX_LIFE;
		sdl->stru_phi[i]->life = MAX_LIFE;
		sdl->stru_phi[i]->can_eat = 1;
		sdl->stru_phi[i]->hurt_me = 0;
		pthread_create(&(sdl->stru_phi[i])->thread, NULL, fn_phi,
			(void*)sdl->stru_phi[i]);
		g_glo->g_chop[i] = 0;
	}
}

int			event(t_sdl *sdl)
{
	int			continuer;
	int			son;

	son = 1;
	continuer = 1;
	Mix_PlayMusic(sdl->music[0], -1);
	sdl_renderall(sdl);
	while (continuer)
	{
		while (SDL_PollEvent(&sdl->event))
		{
			if (sdl->event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				g_glo->end = 1;
				return (-1);
			}
			if (sdl->event.type == SDL_KEYDOWN)
				sound(sdl, &son);
		}
		sdl_renderall(sdl);
		usleep (100000);
		if (g_glo->g_time <= 0)
			continuer = 0;
	}
	return (0);
}

void		*main_2(t_sdl *sdl)
{
	init_all(sdl);
	menu(sdl);
	g_glo->end = 0;
	g_glo->pause = 0;
	g_glo->g_time = TIMEOUT;
	if (event(sdl) == 0)
		end(sdl, 1);
	cleanup(sdl);
	return (NULL);
}
