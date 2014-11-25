/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:13:11 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/25 18:30:56 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include "get_next_line.h"

static void			del(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}

static int			middle(char *s, size_t size, t_list **rest)
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

static void			fill_final_string(char **fill, t_list **lst, int j)
{
	int				len;
	int				i;

	i = 0;
	len = (ft_lstcountbytes(*lst) + 1);
	*fill = malloc(len);
	if (*fill != NULL)
	{
		while (*lst)
		{
			if ((*lst)->next != NULL || j < 0)
			{
				ft_memcpy((*fill + i), (*lst)->content, (*lst)->content_size);
				i += (*lst)->content_size;
			}
			else if ((*lst)->next == NULL)
				ft_memcpy((*fill + i), (*lst)->content, j);
			*lst = (*lst)->next;
		}
		(*fill)[len - 1] = '\0';
		ft_lstdel(lst, del);
	}
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*rest = NULL;
	int				j;
	int				i;
	t_list			*lst;
	char			s[BUFF_SIZE];

	lst = NULL;
	i = (-1);
	j = (-1);
	if (fd < 0 || line == NULL)
		return (i);
	while (j < 0 && i != 0)
	{
		if (rest == NULL)
		{
			i = read(fd, s, BUFF_SIZE);
			if (i == -1)
				return (i);
			if (i != 0)
			{
				if (lst == NULL)
					lst = ft_lstnew(s, i);
				else
					ft_lstaddend(s, i, lst);
				j = middle(s, (size_t)i, &rest);
			}
		}
		else
		{
			lst = rest;
			j = middle((char*)(lst->content), (lst->content_size), &rest);
		}
	}
	if (lst)
	{
		fill_final_string(line, &lst, j);
		return (1);
	}
	else
	{
		return (0);
	}
}
