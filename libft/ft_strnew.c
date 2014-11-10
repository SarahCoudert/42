/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:41:10 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/10 17:48:02 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = NULL;
	ptr = ft_memalloc(size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, size);
	return (ptr);
}
