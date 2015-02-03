/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puiss4.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/27 16:13:55 by gallard           #+#    #+#             */
/*   Updated: 2015/01/16 17:24:14 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISS4_H
# define PUISS4_H

typedef enum		e_case
{
	VIDE,
	JAUNE,
	ROUGE
}					t_case;

# define GRID_W 7
# define GRID_H 6
# define WIN_CNT 4

typedef t_case		t_grid[GRID_H][GRID_W];

/* p4_tool.c */
void	p4_init(t_grid *grid);
void	p4_disp(t_grid *grid);
int		p4_play(t_grid *grid, int col, t_case color);
int		p4_unplay(t_grid *grid, int col, t_case color);
int		p4_legal(t_grid *grid, int col);

/* p4_won.c */
int		p4_won(t_grid *grid, int col);

#endif
