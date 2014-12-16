/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:02:26 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/27 18:09:23 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*sourc;

	sourc = src;
	dest = dst;
	i = 0;
	if (!n)
		n = ft_strlen(src);
	while (i < n && (dest + i))
	{
		dest[i] = sourc[i];
		i++;
	}
	return ((void*)dest);
}
