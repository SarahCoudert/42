/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minilibix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 13:31:28 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/13 13:44:09 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_rgb(int red, int green, int blue)
{
	return (blue + (green + (red * 256)) * 256);
}

int    main()
{
	void *mlx_ptr;
	void *win_ptr;
	int		x;
	int		y;
	int		r;
	int		g;
	int		b;
	int		color;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 510, 510,"BLONDASSE VA !!!");
	x = 0;
	while (x < 510)
	{
		y = 0;
		while (y < 510)
		{
			r = 0;
			g = 0;
			b = 0;
			if (x / 255 == 0 && y / 255 == 0)
			{
				r = x;
				g = 0;
				b = y;
			}
			if (x / 255 == 1 && y / 255 == 0)
			{
				r = 255 - (x % 255);
				g = x % 255;
				b = y;
			}
			if (x / 255 == 0 && y / 255 == 1)
			{
				r = x % 255;
				g = y % 255;
				b = 255 - (y % 255);
			}
			if (x / 255 == 1 && y / 255 == 1)
			{
				if (x >= y)
					g = x % 255;
				else
					g = y % 255;
				if (x / 383 == 0 || y / 383 == 0)
				{
					r = 255 - (x % 255);
					b = 255 - (y % 255);
				}
				else
				{
					g = 255;
					r = 255;
					b = 255;
				}
			}
			if (x / 256 == 1 && y / 256 == 0)
			{
				r = x;
				g = 256 - (y % 256);
				b = 256;
			}
			if (x / 256 == 1 && y / 256 == 1)
			{
				r = 256;
				g = x;
				b = y;
			}
			if (x / 256 == 0 && y / 256 == 0)
			{
				r = x;
				g = g;
				b = b;
			}
			color = ft_rgb(r, g, b);
			mlx_pixel_put(mlx_ptr,win_ptr,x,y,color);
			y++;
		}
		x++;
	}
	while (42);
	return (0);
}
