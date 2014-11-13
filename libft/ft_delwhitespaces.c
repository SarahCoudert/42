/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delwhitespaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 15:40:10 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 18:38:06 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delwhitespaces(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v' 
			|| str[i] == '\f' || str[i] == '\t' || str[i] == ' ')
		i++;
	str = ft_strsub(str, i, ft_strlen(str));
	return (str);
}

int main()
{
	char	str[] = " \t\r\n\v\fbonjour   ";
	char *str2;
	str2 = ft_delwhitespaces(str);
	ft_putstr(str2);
	return (0);
}
