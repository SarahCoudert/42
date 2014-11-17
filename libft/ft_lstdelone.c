#
#
#
#

#include "libft.h"
#include <stdlib.h>

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*ptr;

	ptr = NULL;
	if ((*del) && *alst)
	{
		ptr = *alst;
		free (ptr);
		ptr = NULL;
	}
}
