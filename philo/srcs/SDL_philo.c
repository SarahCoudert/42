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

void			init_begin(t_sdl *sdl)
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
		g_glo->g_bool_chop[i] = 0;
	}
}

int				event(t_sdl *sdl)
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

void				*main_2(void* p_data)
{
	t_sdl	*sdl;

	sdl = (t_sdl*)p_data;
	sdl = (t_sdl*)malloc(sizeof(t_sdl));
	init_all(sdl);
	g_glo->g_time = TIMEOUT;
	if (event(sdl) == 0)
		end(sdl, 1);
	cleanup(sdl);
	return (NULL);
}
