/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:21:42 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/06 10:24:03 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destbis;
	char		*srcbis;
	size_t		i;

	destbis = dest;
	srcbis = (void *)src;
	i = 0;
	while (i < n)
	{
		destbis[i] = srcbis[i];
		i++;
	}
	destbis[i] = '\0';
	return (dest);
}
