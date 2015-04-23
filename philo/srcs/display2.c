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