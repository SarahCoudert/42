/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4_won.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/27 17:03:55 by gallard           #+#    #+#             */
/*   Updated: 2014/09/27 17:04:14 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puiss4.h"

static int		p4_won_hz(t_grid *grid, int col, int row, t_case color)
{
	int		i;
	int		count;

	count = 1;
	i = col;
	while (--i >= 0)
	{
		if ((*grid)[row][i] == color)
			count++;
		else
			break;
	}
	i = col;
	while (++i < GRID_W)
	{
		if ((*grid)[row][i] == color)
			count++;
		else
			break;
	}
	return (count >= WIN_CNT);
}

static int		p4_won_vz(t_grid *grid, int col, int row, t_case color)
{
	int		i;
	int		count;

	count = 1;
	i = row;
	while (--i >= 0)
	{
		if ((*grid)[i][col] == color)
			count++;
		else
			break;
	}
	i = row;
	while (++i < GRID_H)
	{
		if ((*grid)[i][col] == color)
			count++;
		else
			break;
	}
	return (count >= WIN_CNT);
}

static int		p4_won_diag1(t_grid *grid, int col, int row, t_case color)
{
	int		i;
	int		count;

	count = 1;
	i = 1;
	while ((col + i) < GRID_W && (row + i) < GRID_H)
	{
		if ((*grid)[row + i][col + i] == color)
			count++;
		else
			break;
		i++;
	}
	i = -1;
	while ((col + i) >= 0 && (row + i) >= 0)
	{
		if ((*grid)[row + i][col + i] == color)
			count++;
		else
			break;
		i--;
	}
	return (count >= WIN_CNT);
}

static int		p4_won_diag2(t_grid *grid, int col, int row, t_case color)
{
	int		i;
	int		count;

	count = 1;
	i = 1;
	while ((col + i) < GRID_W && (row - i) >= 0)
	{
		if ((*grid)[row - i][col + i] == color)
			count++;
		else
			break;
		i++;
	}
	i = 1;
	while ((col - i) >= 0 && (row + i) < GRID_H)
	{
		if ((*grid)[row + i][col - i] == color)
			count++;
		else
			break;
		i++;
	}
	return (count >= WIN_CNT);
}

int		p4_won(t_grid *grid, int col)
{
	int		i;
	t_case	color;

	i = 0;
	while (i < GRID_H)
	{
		if ((*grid)[i][col] != VIDE)
		{
			color = (*grid)[i][col];
			return (p4_won_vz(grid, col, i, color)
				|| p4_won_hz(grid, col, i, color)
				|| p4_won_diag2(grid, col, i, color)
				|| p4_won_diag1(grid, col, i, color));
		}
		i++;
	}
	return (0);
}