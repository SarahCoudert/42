/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 14:35:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/23 18:33:06 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
** Transforme le fichier recu en parametre par file descriptor en int **tab
*/

t_fdf		**get_map(int fd, int size_array)
{
	char	*map;
	t_list	*array;
	int		j;
	t_fdf	**res;
	t_list	*ptr_array;

	j = 0;
	array = NULL;
	get_next_line(fd, &map);
	ft_lstaddend(map, ft_strlen(map), &array);
	ptr_array = array;
	while (get_next_line(fd, &map) > 0)
		ft_lstaddend(map, ft_strlen(map), &array);
	size_array = countelem(array);
	res = (t_fdf**)ft_strnew(sizeof(t_fdf*) * (size_array + 1));
	while (j < size_array)
	{
		if ((res[j] = ft_strtofdf(array->content, j)) == NULL)
			return (NULL);
		array = array->next;
		j++;
	}
	res[j] = NULL;
	ft_lstdel(&ptr_array, del);
	return (res);
}
