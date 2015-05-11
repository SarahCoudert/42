/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:31:57 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/05 14:31:58 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void				render_plates(t_sdl *sdl, int i, double angle)
{
	SDL_Texture		*tex;

	while (i < NB_PHILO)
	{
		if (sdl->stru_phi[i]->state != EAT)
		{
			tex = sdl->plate[1];
			SDL_QueryTexture(sdl->plate[1], NULL, NULL, &sdl->pos_plate[i].w,
				&sdl->pos_plate[i].h);
		}
		else
		{
			tex = sdl->plate[0];
			SDL_QueryTexture(sdl->plate[0], NULL, NULL, &sdl->pos_plate[i].w,
				&sdl->pos_plate[i].h);
		}
		sdl->pos_plate[i] = create_rect(890 + cos(angle) * 160,
			360 + sin(angle) * 160, sdl->pos_plate[i].w, sdl->pos_plate[i].h);
		angle += (double)(2 * M_PI / 7);
		SDL_RenderCopy(sdl->renderer, tex, NULL, &sdl->pos_plate[i]);
		tex = NULL;
		i++;
	}
}

void				render_time(t_sdl *sdl)
{
	SDL_Surface		*surface[2];
	SDL_Rect		pos[2];
	SDL_Texture		*texture[2];

	sdl->color.r = 255;
	sdl->color.g = 255;
	sdl->color.b = 255;
	pos[0].x = WIDTH_SCREEN - 200;
	pos[0].y = 20;
	pos[1].x = WIDTH_SCREEN - 100;
	pos[1].y = 20;
	surface[0] = TTF_RenderText_Blended(sdl->font, "Time : ", sdl->color);
	surface[1] = TTF_RenderText_Blended(sdl->font, ft_itoa(g_time), sdl->color);
	texture[0] = SDL_CreateTextureFromSurface(sdl->renderer, surface[0]);
	texture[1] = SDL_CreateTextureFromSurface(sdl->renderer, surface[1]);
	SDL_QueryTexture(texture[0], NULL, NULL, &pos[0].w, &pos[0].h);
	SDL_QueryTexture(texture[1], NULL, NULL, &pos[1].w, &pos[1].h);
	SDL_RenderCopy(sdl->renderer, texture[0], NULL, &pos[0]);
	SDL_RenderCopy(sdl->renderer, texture[1], NULL, &pos[1]);
	SDL_DestroyTexture(texture[0]);
	SDL_DestroyTexture(texture[1]);
	SDL_FreeSurface(surface[0]);
	SDL_FreeSurface(surface[1]);
}

void				render_healthbar(t_sdl *sdl, SDL_Rect pos, int i)
{
	int				life;
	SDL_Rect		postext;
	char			*msg;

	sdl->color.r = 0;
	sdl->color.g = 0;
	sdl->color.b = 0;
	life = sdl->stru_phi[i]->life;
	pos.x = 10;
	pos.y += 35;
	pos.w = 250.0 * sdl->stru_phi[i]->life / MAX_LIFE;
	pos.h = 30;
	if (sdl->stru_phi[i]->life > 0)
		sdl->stru_phi[i]->life -= 1;
	else
		end(sdl, -1);
	postext = pos;
	postext.x = 90;
	msg = ft_itoa(life);
	SDL_SetRenderDrawColor(sdl->renderer, rcolor(life), gcolor(life), 0, 255);
	SDL_RenderFillRect(sdl->renderer, &pos);
	render_text(msg, &sdl->color, &postext, sdl);
	postext.x += 40;
	render_text(" / ", &sdl->color, &postext, sdl);
	postext.x += 40;
	msg = ft_itoa(MAX_LIFE);
	render_text(msg, &sdl->color, &postext, sdl);
}

void				render_stats(t_sdl *sdl)
{
	SDL_Rect		pos;
	int				i;
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	i = 0;
	sdl->color.r = 255;
	sdl->color.g = 255;
	sdl->color.b = 255;
	pos = create_rect(0, 0, HEIGHT_SCREEN, 550);
	SDL_SetRenderDrawColor(sdl->renderer, 64, 64, 64, 128);
	SDL_RenderFillRect(sdl->renderer, &pos);
	pos = create_rect(200, 15, 350, 64);
	surface = TTF_RenderText_Blended(sdl->font_e, "STATS", sdl->color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	pos = create_rect(10, 20, 115, 16);
	while (i < NB_PHILO)
	{
		pos.y += 90;
		SDL_QueryTexture(sdl->name_t[i], NULL, NULL, &pos.w, &pos.h);
		SDL_RenderCopy(sdl->renderer, sdl->name_t[i], NULL, &pos);
		render_healthbar(sdl, pos, i);
		render_state(sdl, pos, i);
		i++;
	}
}

void				render_state(t_sdl *sdl, SDL_Rect pos, int i)
{
	SDL_Texture		*texture;
	char			*msg;
	SDL_Surface		*surface;

	msg = NULL;
	sdl->color.r = 255;
	sdl->color.g = 255;
	sdl->color.b = 255;
	if (sdl->stru_phi[i]->state == EAT)
		msg = "is eating";
	else if (sdl->stru_phi[i]->state == REST)
		msg = "is resting";
	else if (sdl->stru_phi[i]->state == THINK)
		msg = "is thinking";
	pos.x = 130;
	surface = TTF_RenderText_Blended(sdl->font, msg, sdl->color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	if (sdl->stru_phi[i]->starve == 1)
	{
	msg = "STARVE";
	pos.x += 130;
	surface = TTF_RenderText_Blended(sdl->font, msg, sdl->color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	}
}
