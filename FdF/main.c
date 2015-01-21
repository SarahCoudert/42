/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:13:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/21 11:03:08 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/get_next_line.h"
#include "fdf.h"
#include <fcntl.h>

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
	s = get_map(fd, 0);
	while (s[j])
	{
		while (i < 5)
		{
			ft_putnbr(s[j][i].x);
			putn();
			ft_putnbr(s[j][i].z);
			putn();
			ft_putnbr(s[j][i].y);
			putn();
			i++;
		}
		i = 0;
		j++;
	}
	while (j < i - 1)
	{
		free(s[j]);
		j++;
	}
	return (0);
}
