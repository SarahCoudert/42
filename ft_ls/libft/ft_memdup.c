/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:19:06 by mgrimald          #+#    #+#             */
/*   Updated: 2015/03/10 14:32:30 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, int len)
{
	char	*dup;

	if ((dup = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	dup[len] = '\0';
	ft_memcpy(dup, s, len);
	return (dup);
}
