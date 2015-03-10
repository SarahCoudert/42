/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:38:37 by mgrimald          #+#    #+#             */
/*   Updated: 2014/12/13 15:53:03 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = (int)size;
	str = (char*)malloc(j + 1);
	while (i <= j)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
