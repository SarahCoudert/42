/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/27 16:13:55 by gallard           #+#    #+#             */
/*   Updated: 2015/01/16 17:24:14 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puiss4.h"

#include <stdio.h>

int		p4_legal(t_grid *grid, int col)
{
	int		i;

	if (col < 0 || col >= GRID_W)
		return (0);
	i = GRID_H;
	while (--i >= 0)
	{
		if ((*grid)[i][col] == VIDE)
		{
			return (1);
		}
	}
	return (0); /* colonne pleine */
}

int		p4_unplay(t_grid *grid, int col, t_case color)
{
	int		i;

	i = 0;
	while (i < GRID_H)
	{
		if ((*grid)[i][col] == color)
		{
			(*grid)[i][col] = VIDE;
			return (1);
		}
		else if ((*grid)[i][col] != VIDE)
			break ; /* erreur, risque de créer une case vide en plein milieu */
		i++;
	}
	return (0); /* erreur */
}

int		p4_play(t_grid *grid, int col, t_case color)
{
	int		i;

	i = GRID_H;
	while (--i >= 0)
	{
		if ((*grid)[i][col] == VIDE)
		{
			(*grid)[i][col] = color;
			return (1);
		}
	}
	return (0); /* colonne pleine / draw */
}

void	p4_init(t_grid *grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < GRID_H)
	{
		j = 0;
		while (j < GRID_W)
		{
			(*grid)[i][j] = VIDE;
			j++;
		}
		i++;
	}
}

void	p4_disp(t_grid *grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < GRID_H)
	{
		j = 0;
		while (j < GRID_W)
		{
			if ((*grid)[i][j] == JAUNE)
				printf("\x1b[93;1m");
			else if ((*grid)[i][j] == ROUGE)
				printf("\x1b[91;1m");
			printf("%c", 'O');
			printf("\x1b[0m");
			j++;
		}
		putchar('\n');
		i++;
	}
}