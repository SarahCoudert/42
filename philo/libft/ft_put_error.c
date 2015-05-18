/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 17:35:14 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/18 17:35:16 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_put_error(char *s, int fd, int ret)
{
	ft_putendl_fd(s, fd);
	exit (ret);
}
