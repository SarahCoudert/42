/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen_db.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:55:56 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/06 16:08:13 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen_db(t_lst_db *lst)
{
	int	i;

	i = 0;
	lst = ft_lstgetstart_db(&lst);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
