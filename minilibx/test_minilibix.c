/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minilibix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 13:31:28 by scoudert          #+#    #+#             */
/*   Updated: 2014/12/11 18:22:33 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_env
{
	void *mlx;
	void *win;
}					t_env;

int	ft_change_color(int color)
{
		color = color + 0x111111;
	return (color);
}

void draw(void *mlx, void *win)
{
	int		x;
	int		y;
	int		color;

	color = 0x000000;
	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
		color = ft_change_color(color);
		mlx_pixel_put(mlx, win, x, y, color);
		x++;
		}
	y++;
	}
}

int		key_hook(int keycode, t_env *e)
{
	printf("key : %d\n", keycode);
	if (keycode == 65307)
	{
		exit(0);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse : %d (%d:%d)", button, x, y);
	return (0);
}

int expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int main()
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
