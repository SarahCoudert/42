/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:36:22 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/23 18:33:04 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
** Transforme un tableau de char contenant des chiffres separes par des espaces
** en un tableau d'int.
*/

void	fill_struct(int y, int x, char *prev_z, t_fdf *res)
{
	t_fdf	str;

	str = *res;
	str.x = x;
	str.y = y;
	str.z = ft_atoi(prev_z);
	str.color = -42;
	str.aff_x = 0;
	str.aff_c = 0;
	*res = str;
}

t_fdf	*ft_strtofdf(const char *s, int line)
{
	t_fdf	**result;
	char	**split;
	int		words;
	int		i;
	t_fdf	*element;

	i = 0;
	words = countword(s, ' ');
	result = NULL;
	if ((result = (t_fdf**)ft_tabnew(sizeof(t_fdf*) * (words))) == NULL)
		return (NULL);
	split = ft_strsplit(s, ' ');
	while (i < words - 1 && split[i])
	{
		element = (t_fdf*)ft_strnew(sizeof(t_fdf));
		fill_struct(line, i, split[i], element);
		result[i] = element;
		i++;
	}
	return (*result);
}
