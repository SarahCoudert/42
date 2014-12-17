/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:20:54 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 17:24:26 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
<<<<<<< HEAD
#include "includes/libft.h"
=======
#include "libft.h"
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		i;
	char	*newstr;

	newstr = NULL;
	i = 0;
	if (s && (*f))
	{
		size = ft_strlen(s);
		newstr = malloc(size + 1);
		if (newstr == NULL)
			return (NULL);
		newstr[size] = '\0';
		while (i < size)
		{
			newstr[i] = (*f)(i, s[i]);
			i++;
		}
		return (newstr);
	}
	return (0);
}
