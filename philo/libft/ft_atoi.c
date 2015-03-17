/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:02:02 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 15:35:51 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		is_negative;
	int		value;

	is_negative = 0;
	value = 0;
	while (*str == '\n' || *str == ' ' || *str == '\r' ||
			*str == '\v' || *str == '\t' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		value = (value * 10) - (*str - '0');
		str++;
	}
	if (!is_negative)
		value = -value;
	return (value);
}
