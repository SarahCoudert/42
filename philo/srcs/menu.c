#include "philo.h"

void			menu(t_sdl *sdl)
{
	SDL_Surface		*surface;
	SDL_Rect		pos;
	SDL_Texture		*texture;
	SDL_Color		color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	pos.x = 200;
	pos.y = 20;
	//scoudert & aiwanesk are proud to introduce to you : \n Philosopher's Dinner !\n\t\tAre they going to Die ? \n\t\tAre they going to survive ?\n\n
	surface = TTF_RenderText_Blended(sdl->font, "Click to launch the presentation", color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
	menu_loop(sdl);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void		menu_loop(t_sdl *sdl)
{
	SDL_Event		event;
	int				continuer;

	continuer = 1;
	while (continuer)
	{
		SDL_PollEvent(&event);
		SDL_SetRenderDrawColor(sdl->renderer, 80, 80, 80, 255);
		SDL_RenderClear(sdl->renderer);
		if (event.type == SDL_MOUSEBUTTONDOWN)
			continuer = 0;
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			continuer = 0;
	}
}