/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 13:26:48 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/10 22:30:58 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <unistd.h>
# include <grp.h>
# include <pwd.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include "libft/includes/libft.h"

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef struct	s_option
{
	int			l;
	int			recur;
	int			a;
	int			s;
	int			t;
	int			r;
	int			no_option;
}				t_option;

typedef struct	s_ls
{
	char		*name;
	struct stat	*info;
	struct s_ls	*next;
	struct s_ls	*prev;
}				t_ls;

void			ls_simple(char **argv, t_lst_db *plst, int i, t_option *opt);
t_lst_db		*t_lsaddend(char *name, struct stat *info, t_lst_db **alst);
t_ls			*t_lsnew(char *name, struct stat *info);

#endif
