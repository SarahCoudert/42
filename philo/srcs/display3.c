
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
		else if (sdl->stru_phi[i]->state == REST)
			display_state(REST, sdl);
		else if (sdl->stru_phi[i]->life <= 0)
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
		// sdl->pos_state[i].x -= sdl->pos_state[i].h;
		// sdl->pos_state[i].y -= sdl->pos_state[i].w;
	}
}

void				display_state(int state, t_sdl *sdl)
{
	SDL_Texture		*texture;


	if (state == 42)
		texture = sdl->state[2];
	else if (state == THINK)
		texture = sdl->state[0];
	else if (state == REST)
		texture = sdl->state[1];
	if (state < 0)
		texture = sdl->state[3];
	SDL_QueryTexture(texture, NULL, NULL, &sdl->pos_state->w,
		&sdl->pos_state->h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, sdl->pos_state);
		if (state < 0)
			end(sdl, -1);
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
