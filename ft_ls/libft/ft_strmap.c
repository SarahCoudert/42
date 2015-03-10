/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:29:48 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/05 18:31:54 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;
	char	*ptr;

	i = 0;
	if (!s || !f)
		return (NULL);
	ptr = (char*)s;
	while (ptr[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(str) * i + 1);
	str[i] = '\0';
	i = 0;
	while (ptr[i] != '\0')
	{
		str[i] = (*f)(ptr[i]);
		i++;
	}
	return (str);
}
