/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_n_sound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:32:03 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/05 14:32:04 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			end(t_sdl *sdl)
{
	SDL_Event	event;
	int			continuer;
	SDL_Surface	*surface;
	SDL_Rect	pos;
	SDL_Texture	*texture;

	sdl->color.r = 255;
	sdl->color.g = 255;
	sdl->color.b = 255;
	pos.x = WIDTH_SCREEN / 2 - 165;
	pos.y = 0;
	surface = TTF_RenderText_Blended(sdl->font_e,
		"Now it is time... To DAAAAAAAANCE!!!", sdl->color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	Mix_PlayChannel(-1, sdl->effect[1], 0);
	continuer = 1;
	SDL_RenderPresent(sdl->renderer);
	while (continuer)
		continuer = end_loop(event);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

int				end_loop(SDL_Event event)
{
	SDL_PollEvent(&event);
	if (event.window.event == SDL_WINDOWEVENT_CLOSE)
		return (0);
	if (event.type == SDL_KEYDOWN)
		return (0);
	return (1);
}

void			init_sound(t_sdl *sdl)
{
	sdl->effect[0] = Mix_LoadWAV("music/whoosh.wav");
	sdl->effect[1] = Mix_LoadWAV("music/yea.wav");
	sdl->music[0] = Mix_LoadMUS("music/music.mp3");
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
