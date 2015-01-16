/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcountbytes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 13:31:52 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/16 13:23:39 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		countbytes(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i += (int)(lst->content_size);
		lst = lst->next;
	}
	return (i);
}
