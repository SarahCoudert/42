/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 13:16:23 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/05/14 13:17:15 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		render_states(t_sdl *sdl)
{
	int			i;

	i = -1;
	while (++i < NB_PHILO)
	{
		if (g_glo->state[i] == THINK)
			display_state(THINK, sdl, i);
		else if (g_glo->state[i] == REST)
			display_state(REST, sdl, i);
		else if (g_glo->state[i] == DEAD)
			display_state(-1, sdl, i);
		else
			display_state(42, sdl, i);
	}
}

void		display_state(int state, t_sdl *sdl, int i)
{
	SDL_Texture		*texture;

	if (state == 42)
		texture = sdl->state[2];
	else if (state == THINK)
		texture = sdl->state[0];
	else if (state == REST)
		texture = sdl->state[1];
	if (state == DEAD)
		texture = sdl->state[3];
	SDL_QueryTexture(texture, NULL, NULL, &sdl->pos_state[i].w,
		&sdl->pos_state[i].h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &sdl->pos_state[i]);
	if (g_glo->end == 1)
		end(sdl, -1);
}

void		render_text(char *s, SDL_Color *color, SDL_Rect *pos,
	t_sdl *sdl)
{
	SDL_Texture		*texture;
	SDL_Surface		*surface;

	surface = TTF_RenderText_Blended(sdl->font, s, *color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos->w, &pos->h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, pos);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}
