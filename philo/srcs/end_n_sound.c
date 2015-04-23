#include "philo.h"

void			end(t_sdl *sdl)
{
	SDL_Event		event;
	int				continuer;
	SDL_Surface		*surface;
	SDL_Rect		pos;
	SDL_Texture		*texture;
	SDL_Color		color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	pos.x = WIDTH_SCREEN / 2 - 450;
	pos.y = 10;
	surface = TTF_RenderText_Blended(sdl->font_m, "Now it is time... To DAAAAAAAANCE!!!", color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	continuer = 1;
	while (continuer)
	{
		continuer = end_loop(sdl, texture, pos, event);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

int			end_loop(t_sdl *sdl, SDL_Texture *texture,
	SDL_Rect pos, SDL_Event event)
{
	SDL_PollEvent(&event);
	sdl_renderall(sdl);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	SDL_RenderPresent(sdl->renderer);
	if (event.window.event == SDL_WINDOWEVENT_CLOSE)
		return (0);
	if (event.type == SDL_KEYDOWN)
		return (0);
	return (1);
}

void		sound(t_sdl *sdl, int son)
{
	if (sdl->event.key.keysym.sym == SDLK_m)
		son = ((son == 1) ? 0 : 1);
	if (son == 1)
		Mix_VolumeMusic(MIX_MAX_VOLUME);
	else
		Mix_VolumeMusic(0);
}
