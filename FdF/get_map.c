/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 10:28:06 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/22 17:20:34 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
** Transforme le fichier recu en parametre par file descriptor en int **tab
*/

t_fdf		**get_map(int fd, int size_ar)
{
	char	*map;
	t_list	*ar;
	int		j;
	t_fdf	**res;
	t_list	*ptr_ar;

	j = 0;
	ar = NULL;
	get_next_line(fd, &map);
	ft_lstaddend(map, ft_strlen(map), &ar);
	ptr_ar = ar;
	while (get_next_line(fd, &map) > 0)
		ft_lstaddend(map, ft_strlen(map), &ar);
	size_ar = countelem(ar);
	res = (t_fdf**)ft_strnew(sizeof(t_fdf*) * (size_ar + 1));
	res[j] = (t_fdf*)ft_strnew((sizeof(t_fdf*) * countword(ar->content, ' ')) + 1);
	while (j < size_ar)
	{
		if ((res[j] = ft_strtoint(ar->content, j)) == NULL)
			return (NULL);
		ar = ar->next;
		j++;
	}
	res[j] = NULL;
	ft_lstdel(&ptr_ar, del);
	return (res);
}
