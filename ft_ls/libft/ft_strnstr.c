/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:55:13 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/12 18:48:23 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)s1;
	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return (str + i);
	while (s1[i] != '\0' && n > i)
	{
		while (s1[i + j] == s2[j] && (n > i + j))
		{
			j++;
			if (s2[j] == '\0')
				return (str + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
