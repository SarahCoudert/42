#
#
#
#

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*first;
	void		*cp_content;
	size_t		cp_size;

	cp_size = 0;
	cp_content = NULL;
	first = NULL;
	first = malloc(sizeof(t_list));
	if (first == NULL)
		return (NULL);
	if (content != NULL)
	{
		cp_content = ft_strdup(content);
		first->content = cp_content;
		cp_size = content_size;
		first->content_size = cp_size;
		first->next = NULL;
	}
	else
	{
		first->content = NULL;
		first->content_size = 0;
		first->next = NULL;
	}
	return (first);
}
