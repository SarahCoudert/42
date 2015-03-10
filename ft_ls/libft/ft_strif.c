/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:43:19 by mgrimald          #+#    #+#             */
/*   Updated: 2015/03/10 19:43:33 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strif(char *str, char *found)
{
	char	*ptr;

	ptr = found;
	while (*str != '\0')
	{
		while (*found != '\0')
		{
			found++;
			if (*found == *str)
				return (str);
		}
		found = ptr;
		str++;
	}
	return (NULL);
}
