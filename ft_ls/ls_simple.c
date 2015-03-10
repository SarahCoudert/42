/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:29:45 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/10 22:36:09 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//plus actuellemnt fonctionnel si tu lui donnes pas le path d'acces
//j'espere que j'ai pas trop massacrer ton code, mais il me semble plus lisible
//et aussi deja un peu plus efficace ;)
//
//allez, passe une bonne journee, a demain et bonne colo
//(si elle est pas deja faite)

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
		print(((t_dirent *)(*plst)->content)->d_name);
	}
}

#include <stdio.h>

void		print_stat(t_stat *stat)
{
	printf("stat->uid : %d\tstat->gid : %d\n", stat->st_uid, stat->st_gid);
}

void		ls_simple(char **argv, t_lst_db *plst, int i, t_option *opt)
{
	DIR				*dir;
	t_dirent	*dirent;
	t_stat		info;

	while (argv[i] != NULL)
	{
		dir = opendir(argv[i]);
		if (*(argv[i]) != '.')
			print(argv[i]);//euh, dans quel cas ?
		if (dir == NULL)
		{
			perror("");
			dirent = NULL;
		}
		while (dirent != NULL)
		{
			if (dirent->d_name[0] != '.')
			{
				stat(dirent->d_name, &info);
				printf("dirent->d_name : %s\n", dirent->d_name);
	(void)opt;//		if (opt->l == 1)
					print_stat(&info);
				//t_lstaddend(dirent->d_name, info, &plst);
			}
			dirent = readdir(dir);
		}
		closedir(dir);
		i++;
	}
	(void)plst;
//	print_all(&plst);
}
