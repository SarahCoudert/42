/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:35:36 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/18 15:35:11 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "includes/libft.h"
=======
#include "libft.h"
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85

size_t		ft_strlen(const char *str)
{
	size_t	 i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	return (i);
}
