/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 11:21:03 by scoudert          #+#    #+#             */
/*   Updated: 2014/12/12 12:58:29 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "includes/libft.h"
#include "includes/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Si le return est different, changer i > 0 en i >= 0 dans le while du main
*/

void		ft_putendli(char *s)
{
	int			i;
	char		n;

	n = '\n';
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write (1, &n, 1);
}

int			main()
{
	int			i;
	int			j;
	int			file;
	int			**result;

	i = 0;
	j = 0;
	file = open("fdf.txt", O_RDONLY);
	result = get_map(file);
	while (i < 6)
	{
		while (j < 10)
		{
			ft_putnbr(result[i][j]);
			ft_putendli("");
			j++;
		}
		ft_putstr("Ligne : ");
		ft_putnbr(i);
		ft_putendli("");
		j = 0;
		i++;
	}
	return (i);
}
