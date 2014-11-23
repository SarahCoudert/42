#
#
#

#include "libft.h"

void	ft_lstaddend(const void *content, size_t content_size, t_list *alst)
{
	t_list		*element;

	element = ft_lstnew(content, content_size);
	if (alst)
	{
		while (alst->next != NULL)
			alst = alst->next;
		if (alst->next == NULL)
			alst->next = element;
	}
}
