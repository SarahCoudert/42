/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 11:27:24 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/18 11:27:27 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*first;
	void		*cp_content;
	size_t		cp_size;

	cp_size = 0;
	cp_content = NULL;
	first = NULL;
	first = malloc(sizeof(t_list));
	if (first == NULL)
		return (NULL);
	if (content != NULL)
	{
		cp_content = malloc(content_size);
		if (cp_content == NULL)
			return (NULL);
		cp_content = ft_memcpy(cp_content, content, content_size);
		first->content = cp_content;
		cp_size = content_size;
		first->content_size = cp_size;
		first->next = NULL;
	}
	else
	{
		first->content = NULL;
		first->content_size = 0;
		first->next = NULL;
	}
	return (first);
}
