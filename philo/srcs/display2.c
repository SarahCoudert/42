#include "philo.h"

void				render_plates(t_sdl *sdl)
{
	SDL_Rect		pos;
	int				i;
	double			angle;
	SDL_Texture		*tex;

	i = 0;
	angle = 0;
	SDL_QueryTexture(sdl->plate[1], NULL, NULL, &pos.w, &pos.h);
	while (i < NB_PHILO)
	{
		if (sdl->stru_phi[i]->state != EAT)
		{
			SDL_QueryTexture(sdl->plate[1], NULL, NULL, &sdl->pos_plate[i].w,
				&sdl->pos_plate[i].h);
			tex = sdl->plate[1];
		}
		else
		{
			SDL_QueryTexture(sdl->plate[0], NULL, NULL, &sdl->pos_plate[i].w,
				&sdl->pos_plate[i].h);
			tex = sdl->plate[0];
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
	SDL_Color		color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	pos[0].x = WIDTH_SCREEN - 200;
	pos[0].y = 20;
	pos[1].x = WIDTH_SCREEN - 100;
	pos[1].y = 20;
	surface[0] = TTF_RenderText_Blended(sdl->font, "Time : ", color);
	surface[1] = TTF_RenderText_Blended(sdl->font, ft_itoa(g_time), color);
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

void			render_healthbar(t_sdl *sdl, SDL_Rect pos, int i)
{
	int			life;
	SDL_Rect	postext;
	SDL_Color	color;
	char		*msg;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	life = sdl->stru_phi[i]->life;
	pos.x = 10;
	pos.y += 35;
	pos.w = 250.0 * sdl->stru_phi[i]->life / MAX_LIFE;
	pos.h = 30;
	if (sdl->stru_phi[i]->life > 0)
		sdl->stru_phi[i]->life -= 1;
	else
		sdl->stru_phi[i]->life  = MAX_LIFE;
	postext = pos;
	postext.x = 90;
	msg = ft_itoa(life);
	SDL_SetRenderDrawColor(sdl->renderer, rcolor(life), gcolor(life), 0, 255);
	SDL_RenderFillRect(sdl->renderer, &pos);
	render_text(msg, &color, &postext, sdl);
	postext.x += 40;
	render_text(" / ", &color, &postext, sdl);
	postext.x += 40;
	msg = ft_itoa(MAX_LIFE);
	render_text(msg, &color, &postext, sdl);
}

void			render_stats(t_sdl *sdl)
{
	SDL_Color	color;
	SDL_Rect	pos;
	int			i;
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	i = 0;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	pos = create_rect(0, 0, HEIGHT_SCREEN, 550);
	SDL_SetRenderDrawColor(sdl->renderer, 64, 64, 64, 128);
	SDL_RenderFillRect(sdl->renderer, &pos);
	pos = create_rect(200, 15, 350, 64);
	surface = TTF_RenderText_Blended(sdl->font_e, "STATS", color);
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

void		render_state(t_sdl *sdl, SDL_Rect pos, int i)
{
	SDL_Texture	*texture;
	SDL_Color	color;
	char		*msg;
	SDL_Surface *surface;

	msg = NULL;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	if (sdl->stru_phi[i]->state == EAT)
		msg = "is eating";
	else if (sdl->stru_phi[i]->state == REST)
		msg = "is resting";
	else if (sdl->stru_phi[i]->state == THINK)
		msg = "is thinking";
	else if (sdl->stru_phi[i]->state == STARVE)
		msg = "is starving";
	pos.x = 130;
	surface = TTF_RenderText_Blended(sdl->font, msg, color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
}