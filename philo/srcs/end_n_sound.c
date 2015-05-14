/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_n_sound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:32:03 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/14 13:18:15 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			end(t_sdl *sdl, int win)
{
	int			continuer;
	SDL_Rect	pos;

	pos.x = WIDTH_SCREEN / 2 - 165;
	pos.y = 0;
	continuer = 1;
	if (win == 1)
	{
		render_text("Now it is time... To DAAAAAAANCE !!!", &pos, sdl,
			sdl->font_e);
		Mix_PlayChannel(-1, sdl->effect[1], 0);
	}
	else
	{
		render_text("Now it is time... To CRYYYYYYYY !!!", &pos, sdl,
			sdl->font_e);
		Mix_PlayChannel(-1, sdl->effect[2], 0);
	}
	SDL_RenderPresent(sdl->renderer);
	end_loop();
	if (win < 0)
		cleanup(sdl);
}

void				end_loop(void)
{
	int			continuer;
	SDL_Event	event;

	continuer = 1;
	while (continuer)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				continuer = 0;
			if (event.type == SDL_KEYDOWN)
				continuer = 0;
		}
	}
}

void			init_sound(t_sdl *sdl)
{
	sdl->music[0] = Mix_LoadMUS("music/music.mp3");
	sdl->effect[0] = Mix_LoadWAV("music/whoosh.wav");
	sdl->effect[1] = Mix_LoadWAV("music/yea.wav");
	sdl->effect[2] = Mix_LoadWAV("music/sad.wav");
}

void			sound(t_sdl *sdl, int *son)
{
	if (sdl->event.key.keysym.sym == SDLK_m)
		*son = ((*son == 1) ? 0 : 1);
	if (*son == 1)
		Mix_VolumeMusic(MIX_MAX_VOLUME);
	else
		Mix_VolumeMusic(0);
}
