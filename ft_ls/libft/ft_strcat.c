/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:23:23 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/18 17:45:31 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "includes/libft.h"
=======
#include "libft.h"
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85

char	*ft_strcat(char *dest, char *src)
{
	size_t		i;
	int			len;

	i = 0;
	len = ft_strlen(dest);
	while (i < (ft_strlen(src) + ft_strlen(dest)))
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	return (dest);
}
