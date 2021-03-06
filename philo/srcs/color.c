/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:31:45 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/14 13:13:44 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char				rcolor(int life)
{
	char			prc;

	prc = 255.0 * (1.0 - ((double)life / (double)MAX_LIFE));
	return (prc);
}

char				gcolor(int life)
{
	char			prc;

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

void				color_fill(SDL_Color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = 255;
}
