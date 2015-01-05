/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 13:31:42 by scoudert          #+#    #+#             */
/*   Updated: 2014/12/08 13:31:43 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(const void *content, size_t content_size, t_list **plst)
{
	t_list		*element;
	t_list		*alst;

	alst = *plst;
	element = ft_lstnew(content, content_size);
	if (alst)
	{
		while (alst->next != NULL)
			alst = alst->next;
		if (alst->next == NULL)
			alst->next = element;
	}
	else
		*plst = element;
}
