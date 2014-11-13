/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:19:55 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 17:06:55 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = NULL;
	ptr = malloc(size);
	if (ptr == NULL)
		return (ptr);
	return (ptr);
}
