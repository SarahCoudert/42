/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 10:28:06 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/13 18:29:40 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
** Transforme le fichier recu en parametre par file descriptor en int **tab
*/

int		**get_map(int fd)
{
	char	*map;
	t_list	*array;
	int		j;
	int		**result;
	int		array_size;
	t_list	**ptr_array;

	j = 0;
	array = NULL;
	array = (t_list *)malloc(sizeof(t_list));
	ptr_array = &array;
	while (get_next_line(fd, &map) > 0)
		ft_lstaddend(map, ft_count_word(map, ' '), &array);
	array_size = ft_lstcountelements(array);
	result = (int **)malloc(sizeof(int) * array_size * ft_lstcountbytes(array));
	while (j < array_size)
	{
		result[j] = malloc(sizeof(int) * ft_count_word(array->content, ' '));
		result[j] = ft_strtoint(array->content);
		array = array->next;
		j++;
	}
	ft_lstdel(&array, del);
	return (result);
}
