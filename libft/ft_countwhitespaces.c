/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwhitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:32:16 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/14 18:39:51 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwhitespaces(char *str)
{
	unsigned int	i;

	i = 0;
	if (str)
	{
		while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v' 
				|| str[i] == '\f' || str[i] == '\t' || str[i] == ' ')
			i++;
		return (i);
	}
	return (0);
}
