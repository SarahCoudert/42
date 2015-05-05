
#include "philo.h"

/*
** state 42 = other
** state -1 = mort
** 
*/

void			render_states(t_sdl *sdl)
{
	int			i;

	i = -1;
	while (++i < NB_PHILO)
	{
		if (sdl->stru_phi[i]->state == THINK)
			display_state(THINK, sdl);
		else if (sdl->stru_phi[i]->state == SLEEP)
			display_state(SLEEP, sdl);
		else if (sdl->stru_phi[i]->live <= 0)
			display_state(-1, sdl);
		else
			display_state(42, sdl);
	}
}

void			init_state_pos(t_sdl *sdl)
{
	int			i;

	i = -1;
	while (++i < NB_PHILO)
	{
		sdl->pos_state[i] = sdl->pos_philo[i];
		sdl->pos_state[i].x -= sdl->pos_state[i].h;
		sdl->pos_state[i].y -= sdl->pos_state[i].w - 10;
	}
}

void				display_state(int state, t_sdl *sdl)
{
	if (state == 42)
		texture = SDL_CreateTextureFromSurface(sdl->renderer, sdl->state[2]);
	else if (state == THINK)
		texture = SDL_CreateTextureFromSurface(sdl->renderer, sdl->state[0]);
	if (state < 0)
		texture = SDL_CreateTextureFromSurface(sdl->renderer, sdl->state[3]);
	SDL_QueryTexture(texture, NULL, NULL, &pos->w, &pos->h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, pos);
	//reste a afficher les etats des philosophes
	//
	//
	//
	//
}

void				render_text(char *s, SDL_Color *color, SDL_Rect *pos,
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
