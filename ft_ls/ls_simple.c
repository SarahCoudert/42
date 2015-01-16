/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:29:45 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/15 11:36:29 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_simple(int ac, char *argv[])
{
	DIR				*dir;
	struct dirent	*dirent;

	if (ac < 3)
	{
		if (ac > 2 && argv[1][0] != '-')
			dir = opendir(argv[1]);
		else if (ac == 1)
			dir = opendir(".");
		if (dir == NULL)
		{
			perror("");
			return ;
		}
		dirent = readdir(dir);
		while (dirent != NULL)
		{
			if (dirent->d_name[0] != '.')
				ft_putendl(dirent->d_name);
			dirent = readdir(dir);
		}
		closedir(dir);
	}
}
