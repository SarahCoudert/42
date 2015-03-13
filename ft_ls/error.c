/* ***************************************************************************/
/*                                                                           */
/*                                                        :::      ::::::::  */
/*   error.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2015/01/23 12:31:09 by scoudert          #+#    #+#            */
/*   Updated: 2015/03/12 17:54:38 by scoudert         ###   ########.fr      */
/*                                                                           */
/* ***************************************************************************/

#include "ft_ls.h"
#include "libft/includes/libft.h"

void	puterrormessage(int error, char erchar)
{
	if (error == 1)
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(erchar);
		putn();
		ft_putendl("usage: ls [-Ralrt] [file ...]");
		return ;
	}
}
