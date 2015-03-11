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

/*
** from Sarah : j'ai corrige (normalement)les fonctions pour les doubles lst
** chainees notamment les listes t_ls, donc ca devrait en theorie marcher, mais
** j'ai quand meme un segfault pour print all.
** Sinon on doit normalement parcourir les fichiers pour les afficher, ce que
** je faisais avant, mais la maintenant ca c'est carrement mis en greve,
** enfin tu verras, essaye de voir comment on peut faire ca, quitte a regarder
** mon ancien code degeu que meme moi j'ai du mal a comprendre x) (genre le
** argv[i], il marche mais WTF qu'est-ce qu'il fout la quoi ??).
** a demain
** P.s : Ce commentaire est a la norme (et c'est le bien).
*/

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

#include <stdio.h> //c'est sale, et tu le sais

void		print_stat(t_stat *stat)
{
	printf("stat->uid : %d\tstat->gid : %d\n", stat->st_uid, stat->st_gid);
}

void		ls_simple(char **argv, t_lst_db *plst, int ac, t_option *opt)
{
	DIR				*dir;
	t_dirent	*dirent;
	t_stat		info;
	int			i;

	i = 0;
	while (i != ac)
	{
		dir = opendir(argv[i]);
		if (*(argv[i]) != '.')
			print(argv[i]);//euh, dans quel cas ? -> on affiche le path, c'est
		//normalement valable que si on affiche plsr trucs et
		//pas seulement le '.', essaye sans, et tu verras la
		//difference.
		if (dir == NULL)
		{
			perror("");
			dirent = NULL;
		}
		if (dirent != NULL)
		{
			if (dirent->d_name[0] != '.')
			{
				stat(argv[i], &info);
				printf("dirent->d_name : %s\n", dirent->d_name);
				(void)opt;//		if (opt->l == 1)
				print_stat(&info);
				t_lsaddend(dirent->d_name, &info, &plst);
			}
			dirent = readdir(dir);
		}
		closedir(dir);
		i++;
	}
	(void)plst;
//	print_all(&plst); ->segfault
}
