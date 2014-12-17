/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:41:10 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 17:22:53 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "includes/libft.h"
=======
#include "libft.h"
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = NULL;
	ptr = ft_memalloc(size + 1);
	if (size + 1)
	{
		if (ptr == NULL)
			return (NULL);
		else
			ft_bzero(ptr, size + 1);
	}
	return (ptr);
}
