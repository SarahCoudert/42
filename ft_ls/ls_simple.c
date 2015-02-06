/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:29:45 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/06 15:39:15 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_simple(int ac, char **argv)
{
	DIR				*dir;
	struct dirent	*dirent;
	int				i;

	i = 0;
	if (ac == 1)
		t_lsaddend();
	while ()
}

static void	print(char *name)
{
	ft_putstr(name);
	ft_putendl(":");
}

static void	aux(char **argv, int ac, DIR *dir, struct dirent *dirent)
{
	int		i;

	i = 1;
	while (i != ac)
	{
		if (ac > 2)
			print(argv[i]);
		dir = opendir(argv[i]);
		if (dir == NULL)
		{
			perror("");
			dirent = NULL;
		}
		else
			dirent = readdir(dir);
		while (dirent != NULL)
		{
			if (dirent->d_name[0] != '.')
				ft_putendl(dirent->d_name);
			dirent = readdir(dir);
		}
		if (dir)
			closedir(dir);
		i++;
		if (ac != i)
		putn();
	}
}

void		ls_simple(int ac, char *argv[])
{
	DIR				*dir;
	struct dirent	*dirent;


	dir = opendir(".");
	dirent = readdir(dir);
	if (ac == 1)
	{
		if (dir == NULL)
		{
			perror("");
			dirent = NULL;
		}
		while (dirent != NULL)
		{
			if (dirent->d_name[0] != '.')
				ft_putendl(dirent->d_name);
			dirent = readdir(dir);
		}
		closedir(dir);
	}
	else
		aux(argv, ac, dir, dirent);
}
