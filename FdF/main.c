/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:13:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/13 15:48:48 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"
#include <fcntl.h>

int		main(int argc, const char *argv[])
{
	int		fd;
	int		**s;
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
	s = get_map(fd);
	while (i < 6)
	{
		while (j < 10)
		{
			ft_putnbr(s[i][j]);
			ft_putendl("");
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
