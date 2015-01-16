/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:36:22 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/16 17:19:53 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
** Transforme un tableau de char contenant des chiffres separes par des espaces
** en un tableau d'int.
*/

int		*ft_strtoint(const char *s)
{
	int		*result;
	char	**split;
	int		words;
	int		i;
	int		j;

	j = 0;
	i = 1;
	words = ft_count_word(s, ' ');
	result = NULL;
	result = (int *)malloc(sizeof(int) * (words + 1));
	split = ft_strsplit(s, ' ');
	result[0] = words;
	while (i < words + 1)
	{
		result[i] = atoi(split[j]);
		i++;
		j++;
	}
	return (result);
}
