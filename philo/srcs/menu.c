#include "philo.h"

void			menu(t_sdl *sdl)
{
	SDL_Surface		*surface;
	SDL_Rect		pos;
	SDL_Texture		*texture[2];
	SDL_Color		color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	surface = TTF_RenderText_Blended(sdl->font_m,
	"Philosopher's dinner by scoudert and aiwanesk ", color);
	texture[0] = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	surface = TTF_RenderText_Blended(sdl->font_m,
	"Click to launch the simulation", color);
	texture[1] = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture[0], NULL, NULL, &pos.w, &pos.h);
	pos.x = WIDTH_SCREEN / 2 - 550;
	pos.y = HEIGHT_SCREEN / 2 - 100;
	SDL_SetRenderDrawColor(sdl->renderer, 140, 140, 140, 255);
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, texture[0], NULL, &pos);
	SDL_QueryTexture(texture[1], NULL, NULL, &pos.w, &pos.h);
	pos.x = WIDTH_SCREEN / 2 - 350;
	pos.y = HEIGHT_SCREEN / 2;
	SDL_RenderCopy(sdl->renderer, texture[1], NULL, &pos);
	SDL_RenderPresent(sdl->renderer);
	menu_loop(sdl);
	SDL_DestroyTexture(texture[0]);
	SDL_DestroyTexture(texture[0]);
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
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			continuer = 0;
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			continuer = 0;
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
					MIX_DEFAULT_CHANNELS, 1024) == -1)
			ft_putendl("Mix_OpenAudio Error");
			sdl->music = Mix_LoadMUS("music/music.mp3");
			Mix_PlayMusic(sdl->music, -1);
		}
	}
}