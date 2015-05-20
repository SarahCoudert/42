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

	i = -1;
	while (++i < NB_PHILO)
	{
		SDL_SetRenderDrawColor(sdl->renderer, sdl->mut_co[i].r,
			sdl->mut_co[i].g, sdl->mut_co[i].b, 255);
		SDL_RenderFillRect(sdl->renderer, &sdl->pos_mut[i]);
		SDL_RenderCopy(sdl->renderer, sdl->philo[i], NULL, &sdl->pos_philo[i]);
	}
}

void				render_chops(t_sdl *sdl)
{
	int				i;
	double			angle;
	SDL_Texture		*tex;

	i = 0;
	angle = 5.8;
	while (i < NB_PHILO)
	{
		tex = sdl->chop[0];
		SDL_QueryTexture(sdl->chop[0], NULL, NULL, &sdl->pos_chop[i].w,
			&sdl->pos_chop[i].h);
		sdl->pos_chop[i] = create_rect(905 + cos(angle) * 275,
			380 + sin(angle) * 270, sdl->pos_chop[i].w, sdl->pos_chop[i].h);
		angle += (double)(2 * M_PI / 7);
		SDL_RenderCopy(sdl->renderer, tex, NULL, &sdl->pos_chop[i]);
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
	sdl->color.r = 255;
	sdl->color.g = 255;
	sdl->color.b = 255;
	SDL_SetRenderDrawColor(sdl->renderer, 80, 80, 80, 255);
	SDL_RenderClear(sdl->renderer);
	render_mutex(sdl);
	render_philo(sdl);
	render_table(sdl);
	render_plates(sdl, 0, 0);
	render_chops(sdl);
	render_names(sdl);
	render_time(sdl);
	render_states(sdl);
	illuminati(sdl);
	render_stats(sdl);
	SDL_RenderPresent(sdl->renderer);
	g_glo->frames++;
	if (g_glo->end == 2)
	{
		SDL_RenderPresent(sdl->renderer);
		g_glo->end = 1;
		end(sdl, -1);
	}
}
