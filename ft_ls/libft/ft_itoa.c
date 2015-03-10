/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:00:25 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/18 18:39:09 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sec_itoa(int n, int p, int i, char *str)
{
	if (n < 0)
		n = -n;
	while (n / 10 > p)
		p = p * 10;
	if (i == 1)
		str[0] = '-';
	while (p >= 1)
	{
		str[i] = ((n / p) % 10) + '0';
		p = p / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	nbr_inside_nbr(int n)
{
	int		nbr;

	nbr = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n >= 1)
	{
		nbr++;
		n = n / 10;
	}
	return (nbr);
}

static char	*ft_spec_nbr(void)
{
	char	*str;

	str = NULL;
	str = ft_strnew(10);
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		p;
	char	*str;

	if (n == -2147483648)
		return (ft_spec_nbr());
	i = 0;
	if (n < 0)
		i = 1;
	p = nbr_inside_nbr(n);
	if ((str = (char*)malloc(sizeof(char) * i + p)) == NULL)
		return (NULL);
	return (ft_sec_itoa(n, 1, i, str));
}
