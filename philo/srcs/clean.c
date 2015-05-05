/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:31:39 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/05 14:31:41 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			cleanup(t_sdl *sdl)
{
	int			i;

	i = -1;
	while (++i < NB_PHILO)
	{
		free (sdl->stru_phi[i]);
		SDL_DestroyTexture(sdl->philo[i]);
		SDL_DestroyTexture(sdl->name_t[i]);
	}
	TTF_CloseFont(sdl->font);
	TTF_CloseFont(sdl->font_m);
	TTF_CloseFont(sdl->font_e);
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

void			destroy_text(t_sdl *sdl)
{
	SDL_DestroyTexture(sdl->table);
	SDL_DestroyTexture(sdl->plate[0]);
	SDL_DestroyTexture(sdl->plate[1]);
	SDL_DestroyTexture(sdl->chop[0]);
	SDL_DestroyTexture(sdl->chop[1]);
	SDL_DestroyTexture(sdl->chop[2]);
	SDL_DestroyTexture(sdl->name_t[0]);
	SDL_DestroyTexture(sdl->name_t[1]);
	SDL_DestroyTexture(sdl->name_t[2]);
	SDL_DestroyTexture(sdl->name_t[3]);
	SDL_DestroyTexture(sdl->name_t[4]);
	SDL_DestroyTexture(sdl->name_t[5]);
	SDL_DestroyTexture(sdl->name_t[6]);
	Mix_FreeChunk(sdl->effect[0]);
	Mix_FreeChunk(sdl->effect[1]);
	Mix_FreeChunk(sdl->effect[2]);
}
