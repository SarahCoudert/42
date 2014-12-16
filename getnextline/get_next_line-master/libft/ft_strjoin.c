/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:08:35 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/12 20:32:34 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = NULL;
	i = ft_strlen((char*)s1);
	j = ft_strlen((char*)s2);
	k = 0;
	str = (char*)malloc(sizeof(char) * (i + j + 1));
	if (str != NULL)
		while (k <= i + j)
		{
			if (k < i)
				str[k] = s1[k];
			if (k >= i && k != i + j)
				str[k] = s2[k - i];
			if (k == i + j)
				str[k] = '\0';
			k++;
		}
	return (str);
}
