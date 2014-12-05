#
#
#

#include "libft.h"

void	ft_lstaddend(const void *content, size_t content_size, t_list **plst)
{
	t_list		*element;
	t_list		*alst;

	alst = *plst;
	element = ft_lstnew(content, content_size);
	if (alst)
	{
		while (alst->next != NULL)
			alst = alst->next;
		if (alst->next == NULL)
			alst->next = element;
	}
	else
		*plst = element;
}
