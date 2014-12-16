/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:44:17 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/12 20:32:53 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)s1;
	j = 0;
	if (s2[j] == '\0')
		return (str);
	while (*str != '\0')
	{
		while (str[j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return (str);
		}
		str++;
		j = 0;
	}
	return (NULL);
}
