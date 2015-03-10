/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:45:02 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/10 14:45:51 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	char		*sourc;

	sourc = (void *)src;
	dest = dst;
	i = 0;
	while (i < n && (dest + i))
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dest);
}
