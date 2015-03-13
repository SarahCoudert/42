/* ***************************************************************************/
/*                                                                           */
/*                                                        :::      ::::::::  */
/*   main.c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2015/01/15 11:31:09 by scoudert          #+#    #+#            */
/*   Updated: 2015/03/12 17:54:38 by scoudert         ###   ########.fr      */
/*                                                                           */
/* ***************************************************************************/

#include "ft_ls.h"
#include "libft/includes/libft.h"


static void		ft_recup_arg(char *arg, t_option *opt, int i)
{
	opt->no_option = 0;
	while (arg[i])
	{
		if (arg[i] == 'l')
			opt->l = 1;
		else if (arg[i] == 'R')
			opt->recur = 1;
		else if (arg[i] == 'a')
			opt->a = 1;
		else if (arg[i] == 'r')
			opt->r = 1;
		else if (arg[i] == 't')
			opt->t = 1;
		else // ft_strif fait planter le tout
		{
			puterrormessage(1, arg[i]);
			return ;
		}
		i++;
	}
}

static void			usearg(t_option *opt, char **av, t_lst_db *db)
{
	(void)av;
	(void)db;
	if (opt->recur == 1 && opt->a != 1)
		return ;
	//fill_recur();
	else if (opt->recur != 1 && opt->a == 1)
		return ;
	//fill_a();
	else if (opt->recur == 1 && opt->a != 1)
		return ;
	//		fill_a_and_recur();
	if (opt->l == 1)
		return ;
	//		fill_l_infos();
	if (opt->t == 1 && opt->r != 1)
		return ;
	//		fill_t();
	else if (opt->t != 1 && opt->r == 1)
		return ;
	//		fill_r();
	else if (opt->r == 1 && opt->t == 1)
		return ;
	//		fill_reverse_time();
}

static t_option	*init(char **dot, int *i)
{
	t_option		*opt;

	*i = 1;
	*dot = malloc(2);
	(*dot)[0] = '.';
	(*dot)[1] = '\0';
	opt = (t_option*)malloc(sizeof(t_option));
	opt->no_option = 1;
	opt->l = 0;
	opt->recur = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	opt->end_opt = 1;
	return (opt);
}

int		main(int ac, char **av)
{
	t_option	*opt;
	t_lst_db	*db;
	int			i;
	char		*dot;

	db = NULL;
	opt = init(&dot, &i);
	while (av[1] != NULL && av[i] != NULL && av[i][0] == '-' && opt->end_opt)
	{
		if (av[i][1] == '-' && av[i][2] == '\0')
			opt->end_opt = 0;
		else
		{
			ft_recup_arg(av[i], opt, 1);
			i++;
		}
	}
	if (ac == 1)
		av[0] = dot;
	while (i != ac && opt->no_option == 1)
	{
		ls_simple(av[i]);
		i++;
	}
	if (opt->no_option == 0)
		usearg(opt, av, db);
	return (0);
}