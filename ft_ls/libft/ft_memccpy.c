/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:22:36 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 17:57:49 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*destbis;
	char	*srcbis;

	destbis = (char *)dest;
	srcbis = (char *)src;
	while (n--)
	{
		*destbis = *srcbis;
		if (*srcbis == c)
			return (destbis + 1);
		destbis++;
		srcbis++;
	}
	return (0);
}
