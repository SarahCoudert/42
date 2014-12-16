/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_db.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 13:47:30 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/26 14:27:24 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_db(t_lst_db **alst, void (*del)(void*, size_t))
{
	t_lst_db	*next_lst;
	t_lst_db	*tmp;

	if (alst)
	{
		next_lst = *alst;
		if ((*alst)->prev)
			((*alst)->prev)->next = NULL;
		while (next_lst != NULL)
		{
			if (del)
				(*del)(next_lst->content, (*next_lst).content_size);
			tmp = next_lst->next;
			free(next_lst);
			next_lst = tmp;
		}
		*alst = NULL;
	}
}
