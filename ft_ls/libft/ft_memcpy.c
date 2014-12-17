/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:21:42 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 17:56:53 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "includes/libft.h"
=======
#include "libft.h"
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*srcbis;
	char	*destbis;
	size_t	i;

	i = 0;
	destbis = dest;
	srcbis = (void *)src;
	while (i < n)
	{
		destbis[i] = srcbis[i];
		i++;
	}
	return (destbis);
}
