/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:13:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/22 17:16:16 by scoudert         ###   ########.fr       */
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
	if ((s = get_map(fd, 0)) == NULL)
		return (-1);
	while (i < 6)
	{
		while (j < 11)
		{
			printf("Ligne : %d\n", s[i][j].y);
			printf("Hauteur : %d\n", s[i][j].z);
			printf("Colomne : %d\n", s[i][j].x);
			printf("Couleur : %d\n", s[i][j].color);
			printf("Aff_x : %d\n\n", s[i][j].aff_x);
			/*ft_putstr("Ligne : ");
			ft_putnbr(s[i][j].y);
			putn();
			ft_putstr("Colomne : ");
			ft_putnbr(s[i][j].x);
			putn();
			ft_putstr("Hauteur : ");
			ft_putnbr(s[i][j].z);
			putn();
			ft_putstr("Couleur : ");
			ft_putnbr(s[i][j].color);
			putn();
			ft_putstr("aff_x : ");
			ft_putnbr(s[i][j].aff_x);
			putn();
			putn();*/
			j++;
		}
		j = 0;
		ft_putendl("");
		i++;
	}
	j = 0;
	while (j < i -1)
	{
		free(s[j]);
		j++;
	}
	return (0);
}
