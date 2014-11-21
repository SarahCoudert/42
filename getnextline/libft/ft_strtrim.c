/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:36:58 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/18 11:28:33 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		whitespacesforward(const char *s)
{
	int		counter;

	counter = 0;
	while (s[counter] == '\n' || s[counter] == ' ' || s[counter] == '\t')
		counter++;
	return (counter);
}

static int		whitespacesbackward(const char *s)
{
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	if (s)
	{
		if ((ft_strlen(s) - 1))
		{
			i = ft_strlen(s) - 1;
			while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
			{
				counter++;
				i--;
			}
		}
	}
	return (counter);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	char	*newstr;
	int		size;

	i = 0;
	size = 0;
	newstr = NULL;
	if (s)
	{
		size = ft_strlen(s);
		newstr = ft_strdup(s);
		if (newstr == NULL)
			return (NULL);
		i = whitespacesforward(newstr);
		if (i == size)
			return (malloc(0));
		size = size - i;
		newstr = ft_strsub(newstr, i, size);
		i = whitespacesbackward(newstr);
		size = size - i;
		newstr = ft_strsub(newstr, 0, size);
		return (newstr);
	}
	return (NULL);
}
