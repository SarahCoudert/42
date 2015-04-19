/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:47:01 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/19 10:15:19 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <unistd.h>

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

int				main(int ac, char **av)
{
	t_sdl		sdl;
	int			continuer;

	(void)ac;
	(void)**av;
	continuer = 1;
	init_all(&sdl);
	if (sdl.screen == NULL)
	{
		ft_putendl_fd("Screen problem", 2);
		return (-1);
	}
	sdl.renderer = SDL_CreateRenderer(sdl.screen, -1, 0);
	sprite_init(&sdl);
	ft_putendl("Sprite init done");
	while (continuer)
	{
		while (SDL_PollEvent(&sdl.event))
			if(sdl.event.window.event == SDL_WINDOWEVENT_CLOSE)
				continuer = 0;
		sdl_renderall(&sdl);
	}
	cleanup(&sdl);
	return (0);
}
