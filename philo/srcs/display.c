#include "philo.h"

void				render_names(t_sdl *sdl)
{
	SDL_Rect		pos;
	int				i;
	double			angle;

	i = -1;
	angle = 0.10;
	while (++i < NB_PHILO)
	{
		pos = create_rect(900 + cos(angle) * 290, 360 + sin(angle) * 290,
			300, 300);
		SDL_QueryTexture(sdl->name_t[i], NULL, NULL, &pos.w, &pos.h);
		angle += (double)2 * M_PI / NB_PHILO;
		SDL_RenderCopy(sdl->renderer, sdl->name_t[i], NULL, &pos);
	}
}

void				render_philo(t_sdl *sdl)
{
	SDL_Rect		pos;
	int				i;
	double			angle;
	SDL_Texture		*texture;

	i = -1;
	angle = 0;
	while (++i < NB_PHILO)
	{
		texture = sdl->philo[i];
		pos = create_rect(900 + cos(angle) * 290, 360 + sin(angle) * 290,
			100, 74);
		angle += (double)2 * M_PI / NB_PHILO;
		SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
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
	SDL_QueryTexture(sdl->chop[0], NULL, NULL, &pos.w, &pos.h);
	while (i < NB_PHILO)
	{
		tex = sdl->chop[0];
		pos = create_rect(905 + cos(angle) * 275, 380 + sin(angle) * 270,
			pos.w, pos.h);
		angle += (double)(2 * M_PI / 7);
		SDL_RenderCopy(sdl->renderer, tex, NULL, &pos);
		i++;
	}
}

void				render_table(t_sdl *sdl)
{
	SDL_Rect		pos;

	SDL_QueryTexture(sdl->table, NULL, NULL, &pos.w, &pos.h);
	pos = create_rect(710, 190, pos.w - 50, pos.h-50);
	SDL_RenderCopy(sdl->renderer, sdl->table, NULL, &pos);
}

void				sdl_renderall(t_sdl *sdl)
{
	SDL_SetRenderDrawColor(sdl->renderer, 80, 80, 80, 255);
	SDL_RenderClear(sdl->renderer);
	init_names_c(sdl);
	init_names_t(sdl);
	render_philo(sdl);
	render_table(sdl);
	render_chops(sdl);
	render_names(sdl);
	SDL_RenderPresent(sdl->renderer);
}