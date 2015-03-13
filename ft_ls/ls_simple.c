/* ***************************************************************************/
/*                                                                           */
/*                                                        :::      ::::::::  */
/*   ls_simple.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2015/01/15 11:29:45 by scoudert          #+#    #+#            */
/*   Updated: 2015/03/10 22:36:09 by mgrimald         ###   ########.fr      */
/*                                                                           */
/* ***************************************************************************/

#include "ft_ls.h"

static void	print(char *name)
{
	ft_putstr(name);
	ft_putendl(":");
}

void		ls_simple(char *folder)
{
	DIR				*dir;
	struct dirent	*dirent;

		dir = opendir(folder);
		if (dir == NULL)
		{
			perror("");
			dirent = NULL;
		}
		dirent = readdir(dir);
			while (dirent != NULL)
			{
				if (dirent->d_name[0] != '.')
				{
					print(dirent->d_name);
				}
				dirent = readdir(dir);
			}
	closedir(dir);
}

/*
					stat(folder, &info);
					print_stat(&info);
					t_lsaddend(dirent->d_name, &info, &plst);*/