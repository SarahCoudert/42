/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:31:57 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/14 14:10:32 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void				render_plates(t_sdl *sdl, int i, double angle)
{
	SDL_Texture		*tex;

	while (i < NB_PHILO)
	{
		if (g_glo->state[i] != EAT)
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
		i++;
	}
}

void				render_time(t_sdl *sdl)
{
	SDL_Surface		*surface[2];
	SDL_Rect		pos[2];
	SDL_Texture		*texture[2];
	char			*msg;

	color_fill(&sdl->color, 255, 255, 255);
	msg = ft_itoa(g_glo->g_time);
	pos[0].x = WIDTH_SCREEN - 200;
	pos[0].y = 20;
	pos[1].x = WIDTH_SCREEN - 100;
	pos[1].y = 20;
	surface[0] = TTF_RenderText_Blended(sdl->font, "Time : ", sdl->color);
	surface[1] = TTF_RenderText_Blended(sdl->font, msg, sdl->color);
	texture[0] = SDL_CreateTextureFromSurface(sdl->renderer, surface[0]);
	texture[1] = SDL_CreateTextureFromSurface(sdl->renderer, surface[1]);
	SDL_QueryTexture(texture[0], NULL, NULL, &pos[0].w, &pos[0].h);
	SDL_QueryTexture(texture[1], NULL, NULL, &pos[1].w, &pos[1].h);
	SDL_RenderCopy(sdl->renderer, texture[0], NULL, &pos[0]);
	SDL_RenderCopy(sdl->renderer, texture[1], NULL, &pos[1]);
	free (msg);
	free_tex(texture, 2);
	free_sur(surface, 2);
}

void				render_healthbar(t_sdl *sdl, SDL_Rect pos, int i)
{
	int				life;
	SDL_Rect		postext;
	char			*msg;

	color_fill(&sdl->color, 0, 0, 0);
	life = g_glo->life[i];
	ft_putendl(ft_itoa(life));
	pos.w = ((life > 0) ? 250.0 * life / MAX_LIFE : 0);
	pos = create_rect(10, pos.y += 35, 30, pos.w);
	postext = pos;
	postext.x = 90;
	if (g_glo->life[i] <= 0)
		g_glo->end = 2;
	msg = ft_itoa(life);
	SDL_SetRenderDrawColor(sdl->renderer, rcolor(life), gcolor(life), 0, 255);
	SDL_RenderFillRect(sdl->renderer, &pos);
	render_text(msg, &postext, sdl, sdl->font);
	free(msg);
	postext.x += 40;
	render_text(" / ", &postext, sdl, sdl->font);
	postext.x += 40;
	msg = ft_itoa(MAX_LIFE);
	render_text(msg, &postext, sdl, sdl->font);
	free(msg);
}

void				render_stats(t_sdl *sdl)
{
	SDL_Rect		pos;
	int				i;
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	i = -1;
	pos = create_rect(0, 0, HEIGHT_SCREEN, 550);
	SDL_SetRenderDrawColor(sdl->renderer, 64, 64, 64, 128);
	SDL_RenderFillRect(sdl->renderer, &pos);
	pos = create_rect(200, 15, 350, 64);
	surface = TTF_RenderText_Blended(sdl->font_e, "STATS", sdl->color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	pos = create_rect(10, 20, 115, 16);
	while (++i < NB_PHILO)
	{
		pos.y += 90;
		SDL_QueryTexture(sdl->name_t[i], NULL, NULL, &pos.w, &pos.h);
		SDL_RenderCopy(sdl->renderer, sdl->name_t[i], NULL, &pos);
		render_healthbar(sdl, pos, i);
		render_state(sdl, pos, i);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
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
	if (g_glo->state[i] == EAT)
		msg = "is eating";
	else if (g_glo->state[i] == REST)
		msg = "is resting";
	else if (g_glo->state[i] == THINK)
		msg = "is thinking";
	pos.x = 130;
	surface = TTF_RenderText_Blended(sdl->font, msg, sdl->color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}
