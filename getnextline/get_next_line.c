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
		temp = malloc(size - i - 1);
		temp = ft_strsub(s, (i + 1), (size - i - 1));
		*rest = ft_lstnew(temp, size - i - 1);
		}
		return (i);
	}
	else
		return (-1);
}

static void			fill_final_string(char **to_fill, t_list **alst, int j)
{
	int				len;
	int				i;

	i = 0;
	len = (ft_lstcountbytes(*alst) + 1);
	*to_fill = malloc(len);
	if (*to_fill != NULL)
	{
		while (*alst)
		{
			if ((*alst)->next != NULL || j < 0)
			{
				ft_memcpy((*to_fill + i), (*alst)->content, (*alst)->content_size);
				i += (*alst)->content_size;
			}
			else if ((*alst)->next == NULL)
				ft_memcpy((*to_fill + i), (*alst)->content, j);
			*alst = (*alst)->next;
		}
		(*to_fill)[len - 1] = '\0';
		ft_lstdel(alst, del);
	}
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*rest = NULL;
	int				j;
	int				i;
	t_list			*alst;
	char			s[BUFF_SIZE];

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
				if (alst == NULL)
					alst = ft_lstnew(s, i);
				else
					ft_lstaddend(s, i, alst);
				j = search_n_and_fill_rest(s, (size_t)i,  &rest);
			}
		}
		else
		{
			alst = rest;
			j = search_n_and_fill_rest((char*)(alst->content), (alst->content_size),  &rest);
		}
	}
	if (alst)
	{
		fill_final_string(line, &alst, j);
		return (1);
	} else {
		return (0);
	}
}
