/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:02:36 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/07 18:20:45 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelall_db(t_lst_db **alst)
{
	t_lst_db	*tmp;

	if (alst && *alst)
	{
		while ((*alst)->prev != NULL)
			*alst = (*alst)->prev;
		while ((*alst) != NULL)
		{
			tmp = (*alst)->next;
			bzero((*alst)->content, (*alst)->content_size);
			free((*alst)->content);
			(*alst)->prev= NULL;
			(*alst)->next= NULL;
			free((*alst));
			*alst = tmp;
		}
	}
}
