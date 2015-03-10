/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:19:24 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/14 19:34:29 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, char const *s2, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = ft_strlen(s1);
	i = size;
	if (s1 == NULL || s2 == NULL)
		return (0);
	j = ft_strlen(s2);
	while (*s1 && size)
	{
		s1++;
		size--;
	}
	if (size == 0)
		return (i + j);
	while (*s2 && size > 1)
	{
		*s1 = *s2;
		s1++;
		s2++;
		size--;
	}
	*s1 = '\0';
	return (k + j);
}
