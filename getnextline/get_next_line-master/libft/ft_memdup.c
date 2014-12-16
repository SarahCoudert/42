/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:19:06 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/30 16:03:25 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, int len)
{
	char	*dup;

	if ((dup = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	ft_memcpy(dup, s, 0);
	return (dup);
}
