/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 11:45:40 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/20 18:14:59 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_countnumbers(int n)
{
	int		i;

	i = 0;
	while (n > 9 || n < 0)
	{
		i++;
		n /= 10;
	}
	i++;
	return (i);
}

static char		*ft_fillstring(int n, char *s, int i)
{
	int		divisor;
	int		result;

	result = 1;
	divisor = 10;
	while (result != 0)
	{
		result = n % divisor;
		if (result< 0)
			s[i] = (result * (-1)) + '0';
		else
			s[i] = result + '0';
		i--;
		n /= 10;
	}
	s[i] = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		booleen;

	booleen = 0;
	i = 0;
	s = NULL;
	if (n < 0)
		booleen += 1;
	if (n == 0)
	{
		s = malloc(2);
		s[0] = 0;
		s[1] = '\0';
		return (s);
	}
	i = ft_countnumbers(n);
	s = malloc(i + 1 + booleen);
	i += booleen;
	s = ft_fillstring(n, s, i);
	if (booleen == 1)
		s[0] = '-';
	return (s);
}
