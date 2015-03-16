/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 11:38:49 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/16 12:08:03 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

static void	print(int count, char **names)
{
	int				i;

	i = 0;
	while (i < count)
	{
		ft_putendl(names[i]);
		i++;
	}
}

void		ls_simple(char *folder)
{
	DIR				*dir;
	struct dirent	*dirent;
	char			**names;
	int				i;

	names = (char **)malloc(1024 * sizeof(char *));
	i = 0;
		dir = opendir(folder);
		if (dir == NULL)
		{
			perror("");
			dirent = NULL;
		}
		dirent = readdir(dir);
			while (dirent != NULL)
			{
				if (dirent->d_name[0] != '\0' && dirent->d_name[0] != '.')
				{
					names[i] = dirent->d_name;
					i++;
				}
				dirent = readdir(dir);
			}
	closedir(dir);
	names = char_sort(names, i);
	print(i, names);
}

/*
					stat(folder, &info);
					print_stat(&info);
					t_lsaddend(dirent->d_name, &info, &plst);*/