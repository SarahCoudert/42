/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:02:02 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/07 18:30:58 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int result;
	int negative;

	negative = 0;
	result = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while ((str[i] > '9' || str[i] < '0') && str[i])
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while ((str[i] <= 57 && str[i] >= 48) && str[i])
	{

		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (negative == 1)
		result = -result;
	return (result);
}
