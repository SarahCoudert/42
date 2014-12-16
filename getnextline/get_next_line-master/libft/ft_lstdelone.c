/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 17:48:42 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/18 16:00:14 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst && *alst)
	{
		if (del)
			del((*alst)->content, (*alst)->content_size);
		(*alst)->content = NULL;
		ft_memdel((void**)alst);
	}
}
