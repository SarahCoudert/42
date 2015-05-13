/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:31:52 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/05 14:31:53 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void				render_names(t_sdl *sdl)
{
	int				i;
	SDL_Texture		*texture;
	SDL_Surface		*surface;
	SDL_Rect		pos;

	i = -1;
	while (++i < NB_PHILO)
	{
		SDL_QueryTexture(sdl->name_t[i], NULL, NULL, &sdl->pos_name[i].w,
			&sdl->pos_name[i].h);
		SDL_RenderCopy(sdl->renderer, sdl->name_t[i], NULL, &sdl->pos_name[i]);
	}
	surface = TTF_RenderText_Blended(sdl->font, "Press M to mute/unmute",
		sdl->color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	pos.y = 750;
	pos.x = 1100;
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void				render_philo(t_sdl *sdl)
{
	int				i;
	SDL_Texture		*texture;

	i = -1;
	while (++i < NB_PHILO)
	{
		texture = sdl->philo[i];
		SDL_RenderCopy(sdl->renderer, texture, NULL, &sdl->pos_philo[i]);
		texture = NULL;
	}
}

void				render_chops(t_sdl *sdl)
{
	SDL_Rect		pos;
	int				i;
	double			angle;
	SDL_Texture		*tex;

	i = 0;
	angle = 5.8;
	while (i < NB_PHILO)
	{
		tex = sdl->chop[0];
		SDL_QueryTexture(sdl->chop[0], NULL, NULL, &pos.w, &pos.h);
		pos = create_rect(905 + cos(angle) * 275, 380 + sin(angle) * 270,
				pos.w, pos.h);
		angle += (double)(2 * M_PI / 7);
		SDL_RenderCopy(sdl->renderer, tex, NULL, &pos);
		tex = NULL;
		i++;
	}
}

void				render_table(t_sdl *sdl)
{
	SDL_Rect		pos;

	SDL_QueryTexture(sdl->table, NULL, NULL, &pos.w, &pos.h);
	pos = create_rect(710, 190, pos.w - 50, pos.h - 50);
	SDL_RenderCopy(sdl->renderer, sdl->table, NULL, &pos);
}

void				sdl_renderall(t_sdl *sdl)
{
	SDL_SetRenderDrawColor(sdl->renderer, 80, 80, 80, 255);
	SDL_RenderClear(sdl->renderer);
	render_philo(sdl);
	render_table(sdl);
	render_plates(sdl, 0, 0);
	render_chops(sdl);
	render_names(sdl);
	render_time(sdl);
	render_stats(sdl);
	render_states(sdl);
	SDL_RenderPresent(sdl->renderer);
}
