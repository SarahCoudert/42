/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lsfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 15:14:02 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/10 17:26:12 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//normalement ca marche mais pas testee

t_lst_db	*t_lsaddend(char *name, struct stat *info, t_lst_db **alst)
{
	t_ls		*lst;

	lst = t_lsnew(name, info);
	ft_lstaddend_db(lst, sizeof(lst), alst);
	return (*alst);
}

t_ls	*t_lsnew(char *name, struct stat *info)
{
	t_ls	*lst;
	lst = (t_ls*)malloc(sizeof(t_ls));
	lst->name = name;
	lst->info = info;
	return (lst);
}
