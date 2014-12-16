/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetend_db.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 20:43:50 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/30 17:31:41 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst_db	**ft_lstgetend_db(t_lst_db **lst)
{
	if (lst && *lst)
	{
		while ((*lst)->next)
		{
			*lst = (*lst)->next;
		}
		ft_putendl((*lst)->content);
	}
	return (lst);
}
