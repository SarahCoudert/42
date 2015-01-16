/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 10:43:58 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/16 13:03:52 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		split(char *s, size_t size, t_list **rest)
{
	size_t			i;
	char			*temp;

	*rest = NULL;
	temp = NULL;
	i = 0;
	while (i < size && s[i] != '\n')
		i++;
	if (i < size)
	{
		if (i < size - 1)
		{
			temp = ft_strsub(s, (i + 1), (size - i - 1));
			*rest = ft_lstnew(temp, size - i - 1);
			free(temp);
		}
		return (i);
	}
	else
		return (-1);
}

static void		fill_final_string(char **to_fill, t_list **plst)
{
	int				len;
	int				i;
	t_list			*alst;

	alst = *plst;
	i = 0;
	len = (countbytes(alst) + 1);
	*to_fill = malloc(len);
	if (*to_fill != NULL)
	{
		while (alst)
		{
			ft_memcpy((*to_fill + i), alst->content, alst->content_size);
			i += alst->content_size;
			alst = alst->next;
		}
		(*to_fill)[len - 1] = '\0';
	}
	ft_lstdel(plst, del);
}

int				gnl_aux(int const fd, t_list **prest, t_list **plst, int *pj)
{
	char			*s;
	int				i;

	s = malloc(BUFF_SIZE);
	if (s == NULL)
		return (-1);
	i = read(fd, s, BUFF_SIZE);
	if (i > 0)
	{
		*pj = split(s, (size_t)i, prest);
		ft_lstaddend(s, ((*pj) < 0 ? (size_t)i : (size_t)(*pj)), plst);
		i = 1;
	}
	free(s);
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*rest = NULL;
	int				j;
	int				i;
	t_list			*alst;

	alst = NULL;
	i = 1;
	j = (-1);
	if (fd < 0 || line == NULL)
		return (-1);
	while (j < 0 && i > 0)
		if (rest == NULL)
			i = gnl_aux(fd, &rest, &alst, &j);
		else
		{
			alst = rest;
			j = split((char*)(alst->content), alst->content_size, &rest);
			alst->content_size = (j < 0 ? alst->content_size : (size_t)j);
		}
	if (alst == NULL)
		return (i);
	fill_final_string(line, &alst);
	return (1);
}
