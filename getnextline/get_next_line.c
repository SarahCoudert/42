#
#
#

#include "libft/libft.h"
#include <stdlib.h>
#include "get_next_line.h"

static void		del(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}

static int		search_n_and_fill_rest(char *s, size_t size, t_list **rest)
{
	size_t				i;
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

static void			fill_final_string(char **to_fill, t_list **plst, int j)
{
	int				len;
	int				i;
	t_list			*alst;

	alst = *plst;
	i = 0;
	len = (ft_lstcountbytes(alst) + 1);
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
		ft_lstdel(plst, del);
	}
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*rest = NULL;
	int				j;
	int				i;
	t_list			*alst;
	char			*s;

	s = malloc(BUFF_SIZE);
	alst = NULL;
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
				j = search_n_and_fill_rest(s, (size_t)i,  &rest);
				ft_lstaddend(s, (j < 0 ? i : j), &alst);
			}
		}
		else
		{
			alst = rest;
			j = search_n_and_fill_rest((char*)(alst->content), (alst->content_size),  &rest);
			alst->content_size = (j < 0 ? alst->content_size : j);
		}
	}
	free(s);
	if (alst)
	{
		fill_final_string(line, &alst, j);
		return (1);
	} else {
		return (0);
	}
}
