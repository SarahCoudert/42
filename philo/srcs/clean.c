#include "philo.h"

void			cleanup(t_sdl *sdl)
{
	int			i;

	i = -1;
	while (++i < NB_PHILO)
	{
		free (sdl->stru_phi[i]);
		SDL_DestroyTexture(sdl->philo[i]);
		SDL_DestroyTexture(sdl->name_t[i]);
	}
	TTF_CloseFont(sdl->font);
	Mix_CloseAudio();
	Mix_Quit();
	SDL_DestroyRenderer(sdl->renderer);
	sdl->renderer = NULL;
	SDL_DestroyWindow(sdl->screen);
	sdl->screen = NULL;
	TTF_Quit();
	SDL_Quit();
	return ;
}

void	destroy_text(t_sdl *sdl)
{
	SDL_DestroyTexture(sdl->table);
	SDL_DestroyTexture(sdl->plate[0]);
	SDL_DestroyTexture(sdl->plate[1]);
	SDL_DestroyTexture(sdl->chop[0]);
	SDL_DestroyTexture(sdl->chop[1]);
	SDL_DestroyTexture(sdl->chop[2]);
}