/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4_getmove_<yourlogin>.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:13:55 by gallard           #+#    #+#             */
/*   Updated: 2015/02/03 17:56:43 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puiss4.h"

static int		p4_perso(t_grid *grid, t_case color, t_case col_adv);
static int		p4_appel(t_grid *grid, t_case color, t_case col_adv, int i);

int		p4_getmove_pbourmea(t_grid *grid, t_case color, int turn_count)
{
	t_case		col_adv;
	(void)turn_count;
	int		ret;

	if ((*grid)[5][3] == VIDE)
		return (3);
	col_adv = (color == 1) ? 2 : 1;
	ret = p4_perso(grid, color, col_adv);
	if (ret >= 0)
		return (ret);
	if ((ret = p4_appel(grid, color, col_adv, 3)) >= 0)
		return (ret);
	if ((ret = p4_appel(grid, color, col_adv, 4)) >= 0)
		return (ret);
	if ((ret = p4_appel(grid, color, col_adv, 2)) >= 0)
		return (ret);
	if ((ret = p4_appel(grid, color, col_adv, 5)) >= 0)
		return (ret);
	if ((ret = p4_appel(grid, color, col_adv, 1)) >= 0)
		return (ret);
	if ((ret = p4_appel(grid, color, col_adv, 6)) >= 0)
		return (ret);
	if ((ret = p4_appel(grid, color, col_adv, 0)) >= 0)
		return (ret);
	if (p4_legal(grid, 3))
		return (3);
	if (p4_legal(grid, 4))
		return (4);
	if (p4_legal(grid, 2))
		return (2);
	if (p4_legal(grid, 5))
		return (5);
	if (p4_legal(grid, 1))
		return (1);
	if (p4_legal(grid, 6))
		return (6);
	if (p4_legal(grid, 0))
		return (0);
	return (-1);
}

static int		p4_appel(t_grid *grid, t_case color, t_case col_adv, int i)
{
	int		ret;

	if (p4_play(grid, i, color))
	{
		ret = p4_perso(grid, color, col_adv);
		p4_unplay(grid, i, color);
		return (ret);
	}
	return (-1);
}
static int		p4_perso(t_grid *grid, t_case color, t_case col_adv)
{
	int		i;
	/*etape 1_0*/
	i = -1;
	while (++i < GRID_W)
		if (p4_play(grid, i, color))
		{
			if (p4_won(grid, i) && p4_unplay(grid, i, color))
				return (i);
			p4_unplay(grid, i, color);
		}
	i = -1;
	while (++i < GRID_W)
		if (p4_play(grid, i, col_adv))
		{
			if (p4_won(grid, i) && p4_unplay(grid, i, col_adv))
				return (i);
			p4_unplay(grid, i, col_adv);
		}
	/*etape 2_1*/
	i = -1;
	while (++i < GRID_W - 1)
		if (p4_play(grid, i, color))
		{
			if (p4_play(grid, i + 1, color))
			{
				if (p4_won(grid, i) && p4_unplay(grid, i, color)
						&& p4_unplay(grid, i + 1, color))
					return (i + 1);
				else if (p4_won(grid, i + 1) && p4_unplay(grid, i, color)
						&& p4_unplay(grid, i + 1, color))
					return (i);
				p4_unplay(grid, i + 1, color);
			}
			p4_unplay(grid, i, color);
		}
	i = -1;
	while (++i < GRID_W - 1)
		if (p4_play(grid, i, col_adv))
		{
			if (p4_play(grid, i + 1, col_adv))
			{
				if (p4_won(grid, i) && p4_unplay(grid, i, col_adv)
						&& p4_unplay(grid, i + 1, col_adv))
					return (i + 1);
				else if (p4_won(grid, i + 1) && p4_unplay(grid, i, col_adv)
						&& p4_unplay(grid, i + 1, col_adv))
					return (i);
				p4_unplay(grid, i + 1, col_adv);
			}
			p4_unplay(grid, i, col_adv);
		}
	/*etape 2_2*/
	i = -1;
	while (++i < GRID_W)
		if (p4_play(grid, i, color))
		{
			if (p4_play(grid, i, color))
			{
				if (p4_won(grid, i) && p4_unplay(grid, i, color)
						&& p4_unplay(grid, i, color))
					return (i);
				p4_unplay(grid, i, color);
			}
			p4_unplay(grid, i, color);
		}
	i = -1;
	while (++i < GRID_W)
		if (p4_play(grid, i, col_adv))
		{
			if (p4_play(grid, i, col_adv))
			{
				if (p4_won(grid, i) && p4_unplay(grid, i, col_adv)
						&& p4_unplay(grid, i, col_adv))
					return (i);
				p4_unplay(grid, i, col_adv);
			}
			p4_unplay(grid, i, col_adv);
		}
	i = -1;
	while (++i < GRID_W - 3)
		if (p4_play(grid, i, color))
		{
			if (p4_play(grid, i + 3, color))
			{
				if (p4_won(grid, i) && p4_unplay(grid, i, color)
						&& p4_unplay(grid, i + 3, color))
					return (i);
				else if (p4_won(grid, i + 3) && p4_unplay(grid, i, color)
						&& p4_unplay(grid, i + 3, color))
					return (i + 3);
				p4_unplay(grid, i + 3, color);
			}
			p4_unplay(grid, i, color);
		}
	i = -1;
	while (++i < GRID_W - 3)
		if (p4_play(grid, i, col_adv))
		{
			if (p4_play(grid, i + 3, col_adv))
			{
				if (p4_won(grid, i) && p4_unplay(grid, i, col_adv)
						&& p4_unplay(grid, i + 3, col_adv))
					return (i);
				else if (p4_won(grid, i + 3) && p4_unplay(grid, i, col_adv)
						&& p4_unplay(grid, i + 3, col_adv))
					return (i + 3);
				p4_unplay(grid, i + 3, col_adv);
			}
			p4_unplay(grid, i, col_adv);
		}
	/*etape 2_3*/
	i = -1;
	while (++i < GRID_W - 2)
		if (p4_play(grid, i, color))
		{
			if (p4_play(grid, i + 2, color))
			{
				if (p4_won(grid, i) && p4_unplay(grid, i, color)
						&& p4_unplay(grid, i + 2, color))
					return (i);
				else if (p4_won(grid, i + 2) && p4_unplay(grid, i, color)
						&& p4_unplay(grid, i + 2, color))
					return (i + 2);
				p4_unplay(grid, i + 2, color);
			}
			p4_unplay(grid, i, color);
		}
	i = -1;
	while (++i < GRID_W - 2)
		if (p4_play(grid, i, col_adv))
		{
			if (p4_play(grid, i + 2, col_adv))
			{
				if (p4_won(grid, i) && p4_unplay(grid, i, col_adv)
						&& p4_unplay(grid, i + 2, col_adv))
					return (i);
				else if (p4_won(grid, i + 2) && p4_unplay(grid, i, col_adv)
						&& p4_unplay(grid, i + 2, col_adv))
					return (i + 2);
				p4_unplay(grid, i + 2, col_adv);
			}
			p4_unplay(grid, i, col_adv);
		}
	return (-1);
}
