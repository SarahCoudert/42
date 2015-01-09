/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 14:53:36 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/09 16:35:34 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Apply yhe atoi function on each content of a linked list and change
** its content size. alst->content is supposed to be a string containing
** an int. If not, the comportment is undertermined.
*/

#include "libft.h"

int		ft_lstatoi(t_list *alst)
{
	while (alst->content != NULL)
	{
		alst->content = ft_atoi(alst->content);
		alst->content_size = sizeof(int);
	}
}
