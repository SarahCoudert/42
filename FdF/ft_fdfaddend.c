/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdfaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 11:02:20 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/21 12:58:56 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "libft.h"

static t_fdf	*fdfnew(int x, int z, int y)
{
	t_fdf	*ret;

	ret = (t_fdf*)ft_strnew(sizeof(t_fdf));
	if (ret == NULL)
		return (NULL);
	if (x && z && y)
	{
		ret->x = x;
		ret->y = y;
		ret->z = z;
	}
	return (ret);
}

void			ft_fdfaddend(int x, int y, int z, t_fdf **lst)
{
	t_fdf		*element;
	t_fdf		*alst;

	alst = *lst;
	element = fdfnew(x, z, y);
	if (alst)
	{
		while (alst->next != NULL)
			alst = alst->next;
		if (alst->next == NULL)
			alst->next = element;
	}
	else
		*lst = element;
}
