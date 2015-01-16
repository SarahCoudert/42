/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:13:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/16 17:19:57 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/get_next_line.h"
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
	s = get_map(fd, 0);
	while (s[i])
	{
		while (j < 11)
		{
			ft_putnbr(s[i][j]);
			ft_putchar(' ');
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
