/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:29:45 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/10 18:04:15 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print(char *name)
{
	ft_putstr(name);
	ft_putendl(":");
}

void		print_all(t_lst_db **plst)
{
	*plst = ft_lstgetstart_db(plst);
	while ((*plst)->next != NULL)
	{
		print((*plst)->content->name);
	}
}

void		ls_simple(int ac, char *argv[], t_lst_db *plst)
{
	DIR				*dir;
	struct dirent	*dirent;
	struct stat		*info;
	int				i;

	i = 0;
	while (i != ac)
	{
		if (ac > 2)
			print(argv[i]);
		if (dir == NULL)
		{
			perror("");
			dirent = NULL;
		}
		while (dirent != NULL)
		{
			if (dirent->d_name[0] != '.')
			{
				stat(dirent->d_name, info);
				t_lsaddend(dirent->d_name, info, &plst);
			}
			dirent = readdir(dir);
		}
		i++;
		closedir(dir);
	}
	print_all(plst);
}
