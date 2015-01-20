/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:36:22 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/19 16:03:15 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
** Transforme un tableau de char contenant des chiffres separes par des espaces
** en un tableau d'int.
*/

t_fdf		*ft_strtostruct(const char *s, int y)
{
	t_fdf	*result;
	char	**split;
	int		words;
	int		i;
	int		j;

	j = 0;
	i = 1;
	words = ft_count_word(s, ' ');
	result = NULL;
	result = (t_fdf*)ft_tabnew(sizeof(t_fdf) * (words));
	split = ft_strsplit(s, ' ');
	while (i < words + 1)
	{
		ft_fdfaddend(i, y, ft_atoi(split[j]), &result);
		i++;
		j++;
	}
	return (result);
}
