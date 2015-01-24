/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:13:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/23 14:06:07 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/get_next_line.h"
#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, const char *argv[])
{
	int		fd;
	t_fdf	**s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = 0;
	if (argc != 2)
	{
		ft_putendl("Map error : Please enter a valid map name");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("Map error : Cannot read or find map");
		return (-1);
	}
	if ((s = get_map(fd)) == NULL)
	{
		ft_putendl("Error : Program abort");
		return (-1);
	}
	while (s[i])
	{
		printf("Nous sommes ligne %d\n", i);
		while (s[i][j].x >= 0)
		{
			printf("Nous sommes a l'index %d :\n", j);
			printf("Ligne : %d\n", s[i][j].y);
			printf("Hauteur : %d\n", s[i][j].z);
			printf("Colomne : %d\n", s[i][j].x);
			printf("Couleur : %d\n", s[i][j].color);
			printf("aff_x : %d\n", s[i][j].aff_x);
			printf("aff_y : %d\n", s[i][j].aff_y);
			j++;
		}
		j = 0;
		ft_putendl("");
		i++;
	}
	j = 0;
	while (j < i)
	{
		free(s[j]);
		j++;
	}
	free(s);
	return (0);
}
