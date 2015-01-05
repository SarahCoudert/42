/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 13:32:26 by scoudert          #+#    #+#             */
/*   Updated: 2014/12/10 14:28:06 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		if ((*alst)->next == NULL)
			ft_lstdelone(alst, del);
		else
		{
			ft_lstdel(&((*alst)->next), del);
			ft_lstdelone(alst, del);
		}
	}
}
