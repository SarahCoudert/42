/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 10:28:06 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/09 15:09:41 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

/*
** Transforme le fichier recu en parametre par file descriptor en int **tab
*/

int		**get_map(int fd)
{
	int		i;
	int		j;
	char	*map;
	char	**array;
	int		**result;

	i = 0;
	j = 0;
	array = (char**)malloc(sizeof(char *) * 200);
	while (get_next_line(fd, &map) > 0)
	{
		array[i] = (char *)malloc(ft_count_word(map, ' '));
		array[i] = map;
		i++;
	}
	result = (int **)malloc(sizeof(int *) * i);
	while (j < i)
	{
		result[j] = (int *)malloc(sizeof(int) * ft_count_word(array[j], ' '));
		result[j] = ft_strtoint(array[j]);
		j++;
	}
	return (result);
}
