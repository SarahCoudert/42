#include "philo.h"

char	rcolor(int life)
{
	char prc;

	prc = 255.0 * (1.0 - ((double)life / (double)MAX_LIFE));
	return (prc);
}

char	gcolor(int life)
{
	char prc;

	prc = 255.0 * ((double)life / (double)MAX_LIFE);
	return (prc);
}

void				color_picker(SDL_Color *color, int hexa, int alpha)
{
	color->r = ((hexa >> 16) & 0xff);
	color->g = ((hexa >> 8) & 0xff);
	color->b = (hexa & 0Xff);
	color->a = alpha;
}

void				render_text(char *s, SDL_Color *color, SDL_Rect *pos,
	t_sdl *sdl)
{
	SDL_Texture *texture;
	SDL_Surface *surface;

	surface = TTF_RenderText_Blended(sdl->font, s, *color);
	texture = SDL_CreateTextureFromSurface(sdl->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &pos->w, &pos->h);
	SDL_RenderCopy(sdl->renderer, texture, NULL, pos);
}