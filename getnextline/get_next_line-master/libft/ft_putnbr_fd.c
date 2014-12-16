/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:29:11 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/26 14:29:11 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			nbr = nbr * (-1);
		}
		if (nbr >= 10)
			ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd);
	}
}
