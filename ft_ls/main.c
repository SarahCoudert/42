/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:31:09 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/16 11:13:02 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/includes/libft.h"

void	puterrormessage(int error)
{
	if (error == 1)
	{
		ft_putstr("ft_ls : illegal option -- ");
		return ;
	}
}

int		*ft_recup_arg(char *arg, t_option opt, int i)
{
	int		*booleen;

	booleen = malloc(10);
	while (arg[i])
	{
		if (arg[i] == 'l')
			opt.l = 1;
		if (arg[i] == 'R')
			opt.recur = 1;
		if (arg[i] == 'a')
			opt.a = 1;
		if (arg[i] == 'r')
			opt.r = 1;
		if (arg[i] == 't')
			opt.t = 1;
		if (arg[i] != 't' || arg[i] != 'a'|| arg[i] != 'l' || arg[i] != 'R' ||
				arg[i] != 'r')
		{
			puterrormessage(1);
			return (NULL);
		}
		i++;
	}
	return (booleen);
}

int		main(int ac, char **argv)
{
	t_option *opt;

	(void)ac;
	opt = (t_option *)malloc(sizeof(t_option));
	opt->l = 0;
	opt->recur = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	if (argv[1][0] == '-')
		if	(ft_recup_arg(argv[1], *opt, 1) == NULL)
			return (-1);
	return (0);
}
