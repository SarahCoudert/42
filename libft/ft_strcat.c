/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:23:23 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/10 11:41:31 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(dest);
	while (i < (ft_strlen(src) + ft_strlen(dest)))
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	return (dest);
}
