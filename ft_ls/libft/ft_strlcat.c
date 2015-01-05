/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:24:42 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/18 11:25:49 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t lendest;
	size_t lensrc;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (size <= lendest)
		return (size + lensrc);
	if (lensrc < size - lendest)
	{
		ft_memcpy(dest + lendest, src, lensrc);
		dest += lendest + lensrc;
	}
	else
	{
		ft_memcpy(dest + lendest, src, size - lendest - 1);
		dest += size - 1;
	}
	*dest = '\0';
	return (lensrc + lendest);
}
