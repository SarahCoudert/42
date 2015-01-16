/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 10:28:06 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/16 17:19:54 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
** Transforme le fichier recu en parametre par file descriptor en int **tab
*/

int				**get_map(int fd, int size_array)
{
	char	*map;
	t_list	*array;
	int		j;
	int		**res;
	t_list	*ptr_array;

	j = 0;
	array = NULL;
	get_next_line(fd, &map);
	ft_lstaddend(map, ft_strlen(map), &array);
	ptr_array = array;
	while (get_next_line(fd, &map) > 0)
		ft_lstaddend(map, ft_strlen(map), &array);
	size_array = countelem(array);
	res = ft_memalloc(sizeof(int) * (size_array + 1));
	while (j < size_array)
	{
		res[j] = malloc((sizeof(int) * ft_count_word(array->content, ' ')) + 1);
		res[j] = ft_strtoint(array->content);
		array = array->next;
		j++;
	}
	res[j] = NULL;
	ft_lstdel(&ptr_array, del);
	return (res);
}
