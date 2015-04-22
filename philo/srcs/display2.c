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
		tex = sdl->plate[1];
		pos = create_rect(890 + cos(angle) * 160, 360 + sin(angle) * 160,
			pos.w, pos.h);
		angle += (double)(2 * M_PI / 7);
		SDL_RenderCopy(sdl->renderer, tex, NULL, &pos);

		tex = NULL;
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
		SDL_PollEvent(&event);
		sdl_renderall(sdl);
		SDL_RenderCopy(sdl->renderer, texture, NULL, &pos);
		SDL_RenderPresent(sdl->renderer);
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			continuer = 0;
		if (event.type == SDL_KEYDOWN)
			continuer = 0;
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}