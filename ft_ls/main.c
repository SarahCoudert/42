/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:31:09 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/10 22:32:19 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/includes/libft.h"

void	puterrormessage(int error, char erchar)
{
	if (error == 1)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(erchar);
		putn();
		ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
		return ;
	}
}

void		ft_recup_arg(char *arg, t_option *opt, int i)
{
	opt->no_option = 0;
	while (arg[i])
	{
		if (arg[i] == 'l')
			opt->l = 1;
		if (arg[i] == 'R')
			opt->recur = 1;
		if (arg[i] == 'a')
			opt->a = 1;
		if (arg[i] == 'r')
			opt->r = 1;
		if (arg[i] == 't')
			opt->t = 1;
		if (ft_strif(arg, "talrR") == NULL)
		{
			puterrormessage(1, arg[i]);
			return ;
		}
		i++;
	}
}

void			usearg(t_option *opt)
{
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

int		main(int ac, char **argv)
{
	t_option	*opt;
	t_lst_db	*db;
	int			i;

	(void)ac;
	db = NULL;
	//Quelle raison de creer db dans le main ?
	opt = (t_option *)malloc(sizeof(t_option));
	bzero(opt, sizeof(t_option));
	//alt aux deux lignes au dessus: 
	//opt = (t_option*)ft_strnew(sizeof(t_option) - 1);
	opt->no_option = 1;
	i = 1;
	while (argv[i] != NULL && argv[i][0] == '-')
		ft_recup_arg(argv[i], opt, 1);
	if (argv[i] == NULL)
	{
		argv = (char**)ft_strnew(sizeof(char*) * 2 -1);
		*argv = ft_strnew(sizeof(char) * 1);
		**argv = '.';
	}
	ls_simple(argv, db, i, opt);
	//	usearg(opt);
	return (0);
}
