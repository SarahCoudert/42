/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellone_db.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:06:24 by mgrimald          #+#    #+#             */
/*   Updated: 2014/12/17 15:16:18 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdellone_db(t_lst_db **alst)
{
	t_lst_db	*temp;

	temp = NULL;
	if (alst && (*alst))
	{
		if ((*alst)->prev)
		{
			(*alst)->prev->next = (*alst)->next;
			temp = (*alst)->prev;
		}
		if ((*alst)->next)
		{
			(*alst)->next->prev = (*alst)->prev;
			temp = (*alst)->next;
		}
		(*alst)->content_size = 0;
		free(*alst);
		*alst = temp;
	}
}
