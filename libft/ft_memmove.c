/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:22:58 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/06 10:23:03 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;

	temp = (char*)malloc(n * sizeof(char *));
	if (temp == NULL)
	{
		return (NULL);
	}
	temp = ft_strncpy(temp, src, n);
	dest = (void *)ft_strncpy(dest, temp, n);
	free (temp);
	return (dest);
}
