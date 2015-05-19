/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 13:16:23 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/05/18 14:27:49 by aiwanesk         ###   ########.fr       */
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
		texture = sdl->state[1];
	else if (state == REST)
		texture = sdl->state[0];
	if (state == DEAD)
		texture = sdl->state[3];
	SDL_QueryTexture(texture, NULL, NULL, &sdl->pos_state[i].w,
		&sdl->pos_state[i].h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &sdl->pos_state[i]);
}

void		render_text(char *s, SDL_Rect *pos, t_sdl *sdl, TTF_Font *font)
{
	SDL_Texture		*texture;
	SDL_Surface		*surface;

	surface = TTF_RenderText_Blended(font, s, sdl->color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos->w, &pos->h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, pos);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void		init_color(t_sdl *sdl)
{
	color_fill(&sdl->mut_co[0], 0, 0, 255);
	color_fill(&sdl->mut_co[1], 255, 140, 140);
	color_fill(&sdl->mut_co[2], 140, 255, 157);
	color_fill(&sdl->mut_co[3], 255, 177, 34);
	color_fill(&sdl->mut_co[4], 240, 0, 204);
	color_fill(&sdl->mut_co[5], 255, 255, 0);
	color_fill(&sdl->mut_co[6], 200, 0, 0);
}

void		render_mutex(t_sdl *sdl)
{
	int			i;
	SDL_Rect	pos;

	i = 0;
	(void)sdl;
	while (i < NB_PHILO)
	{
		pos = sdl->pos_chop[LEFT_BUDDY(i)];
		pos.h = 20;
		pos.w = 20;
		if (g_glo->g_chop[i] == 1)
		{
			SDL_SetRenderDrawColor(sdl->renderer, sdl->mut_co[i].r,
				sdl->mut_co[i].g, sdl->mut_co[i].b, 255);
			SDL_RenderFillRect(sdl->renderer, &pos);
		}
		else if (g_glo->g_chop[i] == 2)
		{
			SDL_SetRenderDrawColor(sdl->renderer, sdl->mut_co[LEFT_BUDDY(i)].r,
				sdl->mut_co[LEFT_BUDDY(i)].g,
				sdl->mut_co[LEFT_BUDDY(i)].b, 255);
			SDL_RenderFillRect(sdl->renderer, &pos);
		}
		i++;
	}
}
