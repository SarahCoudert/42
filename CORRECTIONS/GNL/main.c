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
#include "libft/includes/libft.h"
#include "get_next_line.h"
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

int			main(void)
{
	char		*s;
	int			i;
	int			file;

	i = 42;
	file = open("compare.txt", O_RDONLY);
	while (i > 0)
	{
		s = NULL;
		i = get_next_line(file, &s);
		if (i > 0)
		{
			ft_putendli(s);
			free(s);
		}
	}
	close(file);
	return (i);
}
