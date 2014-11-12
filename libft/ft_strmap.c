/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:20:36 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/12 10:20:39 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	int		i;
	char	*newstr;

	newstr = NULL;
	i = 0;
	if (s && (*f) != NULL)
	{
		size = ft_strlen(s);
		newstr = malloc(size + 1 * sizeof(char));
		if (newstr == NULL)
			return (NULL);
		newstr[size + 1] = '\0';
		while (i < size)
		{
			(*f)(newstr[i]);
			i++;
		}
		return (newstr);
	}
	return (0);
}
