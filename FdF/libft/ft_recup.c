/*  ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillau <mguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 10:53:28 by mguillau          #+#    #+#             */
/*   Updated: 2015/01/09 16:35:37 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_set_map(int fd)
{
	char	*line;
	int		**map;
	char	**array;
	t_lst	*lst;
	t_lst	**alst;
	int		i;

	i = 0;
	line = NULL;
	alst = &line;
	while (get_next_line(fd, &line) > 0)
	{
		array = ft_strsplit(line, ' ');
		ft_lstiter(lst->content, &ft_atoi);
		lst = ft_lstnew(NULL, 0);
		lst->content = array;
		lst->content_size = ft_count_word(line, ' ');
		ft_lstadd(alst, lst);
	}
	while (lst != NULL)
		lst = lst->next;
	lst = *alst;
	map = malloc(sizeof(int*) * (ft_count_maillon(alst) + 1));
	while (lst != NULL)
	{
		map[i] = lst->content;
		i++;
		lst = lst->next;
		map[i] = NULL;
	}
	ft_lstdel(alst);
	return (map);
}
