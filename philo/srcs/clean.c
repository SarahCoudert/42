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
		SDL_DestroyTexture(sdl->philo[i]);
	}
	destroy_text(sdl);
	TTF_CloseFont(sdl->font);
	TTF_CloseFont(sdl->font_m);
	TTF_CloseFont(sdl->font_e);
	Mix_CloseAudio();
	Mix_Quit();
	SDL_DestroyRenderer(sdl->renderer);
	sdl->renderer = NULL;
	SDL_DestroyWindow(sdl->screen);
	sdl->screen = NULL;
	free(g_glo);
	TTF_Quit();
	SDL_Quit();
	exit(0);
}

void			destroy_text(t_sdl *sdl)
{
	SDL_DestroyTexture(sdl->table);
	SDL_DestroyTexture(sdl->plate[0]);
	SDL_DestroyTexture(sdl->plate[1]);
	SDL_DestroyTexture(sdl->chop[0]);
	SDL_DestroyTexture(sdl->chop[1]);
	SDL_DestroyTexture(sdl->chop[2]);
	free_tex (sdl->name_t, 7);
	Mix_FreeChunk(sdl->effect[0]);
	Mix_FreeChunk(sdl->effect[1]);
	Mix_FreeChunk(sdl->effect[2]);
	Mix_FreeChunk(sdl->effect[3]);
}

void		free_sur(SDL_Surface **sur, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		SDL_FreeSurface(sur[j]);
		j++;
	}
}

void		free_tex(SDL_Texture **tex, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		SDL_DestroyTexture(tex[j]);
		j++;
	}

}