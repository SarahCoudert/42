/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:24:26 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 17:27:32 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*newstr;
	int		i;

	i = ft_strlen(s);
	newstr = malloc(i * sizeof(char));
	if (newstr == NULL)
	{
		return (NULL);
	}
	ft_strcpy(newstr, s);
	return (newstr);
}
