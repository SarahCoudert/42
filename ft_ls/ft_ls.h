/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 13:26:48 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/02 15:51:58 by scoudert         ###   ########.fr       */
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
# include "libft/includes/libft.h"
# include <stdio.h>

void			ls_simple(int ac, char **argv);

typedef struct	s_option
{
	int			l;
	int			recur;
	int			a;
	int			s;
	int			t;
	int			r;
}				t_option;

typedef struct	s_ls
{
	char		*name;
	struct stat	infos;
}				t_ls;

#endif
