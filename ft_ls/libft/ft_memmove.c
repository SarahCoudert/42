/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:03:05 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 17:54:24 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "includes/libft.h"
=======
#include "libft.h"
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destbis;
	char		*srcbis;

	destbis = dest;
	srcbis = (void *)src;
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	while (n)
	{
		n--;
		destbis[n] = srcbis[n];
	}
	return (dest);
}
