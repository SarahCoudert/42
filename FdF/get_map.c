/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 10:28:06 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/21 12:59:01 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
** Transforme le fichier recu en parametre par file descriptor en double 
** tableau de pointeurs sur structures
*/


t_fdf				*ft_strtostruct(const char *s, int y)
{
	t_fdf*	result;
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
		ft_fdfaddend((i - 1), y, ft_atoi(split[j]), &result);
		i++;
		j++;
	}
	return (result);
}

t_fdf				**get_map(int fd, int size_array)
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
	res = (t_fdf**)ft_memalloc(sizeof(t_fdf*) * (size_array + 1));
	res[j] = malloc((sizeof(t_fdf) * ft_count_word(array->content, ' ')) + 1);
	while (j < size_array)
	{
		res[j] = ft_strtostruct(array->content, j);
		array = array->next;
		j++;
	}
	res[j] = NULL;
	ft_lstdel(&ptr_array, del);
	return (res);
}
