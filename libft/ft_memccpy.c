/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:22:36 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/10 16:52:11 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*destbis;
	char	*srcbis;

	i = 0;
	destbis = dest;
	srcbis = (void *)src;
	while (i < n && srcbis[i] != c)
	{
		destbis[i] = srcbis[i];
		if (srcbis[i] == c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
