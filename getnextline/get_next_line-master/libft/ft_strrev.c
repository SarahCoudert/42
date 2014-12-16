/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 20:07:43 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/26 14:39:22 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_strlen(str) - 1;
	if ((temp = ft_strnew(i)) == NULL)
		return (NULL);
	while (i > 0)
	{
		temp[j] = str[i];
		i--;
		j++;
	}
	temp[j] = '\0';
	ft_strcpy(str, temp);
	free(temp);
	return (str);
}
