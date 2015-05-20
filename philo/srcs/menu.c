/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:32:16 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/14 13:18:25 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void				menu(t_sdl *sdl)
{
	SDL_Surface		*surface;
	SDL_Rect		pos;
	SDL_Texture		*texture[2];

	sdl->color.r = 0;
	sdl->color.g = 0;
	sdl->color.b = 0;
	surface = TTF_RenderText_Blended(sdl->font_m,
		"Philosopher's dinner by scoudert and aiwanesk ", sdl->color);
	texture[0] = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	surface = TTF_RenderText_Blended(sdl->font_m,
		"Click to launch the simulation", sdl->color);
	texture[1] = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture[0], NULL, NULL, &pos.w, &pos.h);
	pos.x = WIDTH_SCREEN / 2 - 550;
	pos.y = HEIGHT_SCREEN / 2 - 100;
	SDL_SetRenderDrawColor(sdl->renderer, 140, 140, 140, 255);
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, texture[0], NULL, &pos);
	SDL_QueryTexture(texture[1], NULL, NULL, &pos.w, &pos.h);
	pos.x = WIDTH_SCREEN / 2 - 350;
	pos.y = HEIGHT_SCREEN / 2;
	SDL_RenderCopy(sdl->renderer, texture[1], NULL, &pos);
	SDL_RenderPresent(sdl->renderer);
	menu_loop(sdl, surface, texture);
}

void				menu_loop(t_sdl *sdl, SDL_Surface *sur, SDL_Texture **tex)
{
	SDL_Event		event;
	int				continuer;

	continuer = 1;
	while (continuer)
	{
		SDL_WaitEvent(&event);
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			continuer = 0;
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			Mix_PlayChannel(-1, sdl->effect[0], 0);
			continuer = 0;
		}
	}
	SDL_DestroyTexture(tex[0]);
	SDL_DestroyTexture(tex[1]);
	SDL_FreeSurface(sur);
}

void				illuminati(t_sdl *sdl)
{
	SDL_Rect		pos;

	SDL_QueryTexture(sdl->illu, NULL, NULL, &pos.w, &pos.h);
	pos.x = 650;
	pos.y = 100;
	if (g_glo->illuminati == 1)
		Mix_PlayChannel(-1, sdl->effect[3], 0);
	if (g_glo->illuminati > 0)
	{
		SDL_RenderCopy(sdl->renderer, sdl->illu, NULL, &pos);
		g_glo->illuminati++;
	}
	if (g_glo->illuminati == 30)
		g_glo->illuminati = 0;
}
