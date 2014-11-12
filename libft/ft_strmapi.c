/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:20:54 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/12 10:20:55 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				size;
	unsigned int	i;
	char			*newstr;

	if (s && (*f))
	{
		newstr = NULL;
		i = 0;
		size = ft_strlen(s);
		newstr = malloc(size * sizeof(char));
		if (newstr == NULL)
			return (NULL);
		while ((int)i < size)
		{
			(*f)(i, newstr[i]);
			i++;
		}
		return (newstr);
	}
	return (0);
}
