/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:54:12 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 18:08:36 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "includes/libft.h"
=======
#include "libft.h"
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85

void	*ft_strrev(char *str, size_t size)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = NULL;
	if (str && size > 0)
	{
		temp = ft_memalloc(size);
		temp = ft_strcpy(temp, str);
		while (i < size)
		{
			str[size] = temp[i];
			size--;
			i++;
		}
	}
	return (str);
}
