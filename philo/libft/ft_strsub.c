/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:15:47 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/05 14:04:06 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = NULL;
	if (s != NULL)
	{
		ptr = malloc((len + 1) * sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[len] = '\0';
		while (i < len + start)
		{
			if (i >= start)
				ptr[i - start] = s[i];
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
