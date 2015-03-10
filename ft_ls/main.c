/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:31:09 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/10 17:48:22 by scoudert         ###   ########.fr       */
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
		if (arg[i] != 't' && arg[i] != 'a' && arg[i] != 'l' && arg[i] != 'R' &&
				arg[i] != 'r')
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

	db = NULL;
	opt = (t_option *)malloc(sizeof(t_option));
	opt->l = 0;
	opt->recur = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	if (ac == 1 || argv[1][0] != '-' )
		ls_simple(ac, argv, db);
	else if (ac > 1 && argv[1][0] == '-')
		ft_recup_arg(argv[1], opt, 1);
	usearg(opt);
	return (0);
}
