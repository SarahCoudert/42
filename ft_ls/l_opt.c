/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_opt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 14:20:15 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/10 22:38:41 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void		fill_struct(t_ls *stru, struct stat *stat)
{
	(void)stru;
	(void)stat;
}

void		print_all(t_lst_db **plst)
{
	*plst = ft_lstgetstart_db(plst);
	while ((*plst)->next != NULL)
	{
		ft_putstr(((t_dirent *)(*plst)->content)->d_name);
	}
}
