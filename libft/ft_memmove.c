/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:22:58 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/07 16:42:43 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destbis;
	char		*srcbis;

	destbis = dest;
	srcbis = (void *)src;
	if (dest <= src)
		return(ft_memcpy(dest, src, n));
	while (n)
	{
		n--;
		destbis[n] = srcbis[n];
	}
	return (dest);
}
