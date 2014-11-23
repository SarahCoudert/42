#
#
#

#include "libft/libft.h"
#include <stdlib.h>
#include "get_next_line.h"

static int		search_n_and_fill_rest(char *s, char *rest)
{
	int				i;

	i = 0;
	while (s[i] != '\n' && i < BUFF_SIZE)
		i++;
	if (i < BUFF_SIZE)
	{
		rest = malloc(i + 1);
		rest = ft_strsub(s,  0, i);
		rest[i + 1] = '\0';
		return (i);
	}
	else
		return (-1);
}

static void		fill_final_string(char *to_fill, t_list *alst, int j)
{
	int				len;

	len = ((ft_lstcountelements(alst) - 1) * BUFF_SIZE) + j + 1;
	to_fill = malloc(len);
	while (alst->next)
	{
		if (alst->next != NULL)
		{
			ft_memcpy(to_fill, alst->content, BUFF_SIZE);
			alst = alst->next;
		}
		else if (alst->next == NULL)
			ft_memcpy(to_fill, alst->content, j);
		to_fill[len] = '\0';
	}
}

int				get_next_line(int const fd, char **line)
{
	static char		*rest;
	int				j;
	int				i;
	t_list			*alst;
	char			s[BUFF_SIZE];

	alst = NULL;
	i = (-1);
	j = (-1);
	if (fd < 0 || line == NULL)
		return (i);
	while (j < 0)
	{
		i = read(fd, s, BUFF_SIZE);
		if (i == (-1))
			return (i);
		if (alst == NULL)
			alst = ft_lstnew(s, BUFF_SIZE);
		else
			ft_lstaddend(s, BUFF_SIZE, alst);
		j = search_n_and_fill_rest(s, rest);
	}
	fill_final_string(*line, alst, j);
	if (rest == NULL)
		return (-1);
	return (1);
}
