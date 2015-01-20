/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:52:21 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/19 15:57:58 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MAX_X 200
# define MAX_Y 200

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "libft.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_fdf
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				aff_x;
	int				aff_y;
	int				aff_c;
	struct s_fdf	*next;
}					t_fdf;

typedef	struct		s_trace
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				c1;
	int				c2;
}					t_trace;

t_fdf				***fdf_proj_iso(t_fdf ***map, int c1, int c2);
t_fdf				***fdf_proj_paral(t_fdf ***map, int cst);
void				ft_trace_segm(t_fdf p1, t_fdf p2, t_env *env);
void				trace_0(t_trace t, t_env *env);
void				trace_1(t_trace t, int e, t_env *env);
void				trace_2(t_trace t, int e, t_env *env);
void				trace_3(t_trace t, int e, t_env *env);
void				trace_4(t_trace t, int e, t_env *env);
t_fdf				*ft_strtostruct(const char *s, int y);
t_fdf				**get_map(int fd, int size_array);
void				ft_fdfaddend(int x, int y, int z, t_fdf **lst);

#endif
