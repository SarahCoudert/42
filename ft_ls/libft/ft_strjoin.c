/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:13:53 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/18 17:44:38 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			size;
	char		*str;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = NULL;
	if (s1 && s2)
	{
		str = malloc((size + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[size] = '\0';
		ft_memcpy(str, s1, (ft_strlen(s1) + 1));
		ft_strcat(str, (char *)s2);
	}
	return (str);
}
