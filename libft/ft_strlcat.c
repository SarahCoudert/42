/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:24:42 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/12 10:22:32 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		sizdest;
	size_t		sizsrc;

	sizdest = ft_strlen(dest);
	sizsrc = ft_strlen(dest);
	if (sizdest < size)
		return (sizdest + sizsrc);
	if (size > 0 && dest[0])
	{
		if (sizsrc < size - sizdest)
		{
			ft_memcpy(dest + sizdest, src, sizsrc);
			dest += sizdest + sizsrc;
		}
		else
		{
			ft_memcpy(dest + sizdest, src, size - sizdest - 1);
			dest += size - 1;
		}
		*dest = '\0';
		return (sizsrc + sizdest);
	}
	return (sizsrc + sizdest);
}
