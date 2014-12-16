/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_db.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:00:16 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/28 14:28:31 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdlone_db(t_lst_db **alst, void (*del)(void*, size_t))
{
	if (alst && *alst)
	{
		if ((*alst)->prev || (*alst)->next)
		{
			if ((*alst)->prev)
				((*alst)->prev)->next = (*alst)->next;
			if ((*alst)->next)
				((*alst)->next)->prev = (*alst)->prev;
		}
		if (del)
			del((*alst)->content, (*alst)->content_size);
		(*alst)->content = NULL;
		ft_memdel((void**)alst);
	}
}
