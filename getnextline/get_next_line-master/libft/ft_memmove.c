/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:20:12 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/10 11:50:10 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sourc;

	sourc = (char *)src;
	dest = dst;
	if (dest <= sourc)
		return (ft_memcpy(dst, src, n));
	while (n)
	{
		n--;
		dest[n] = sourc[n];
	}
	return (dst);
}
