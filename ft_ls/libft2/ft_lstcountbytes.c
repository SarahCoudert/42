#
#
#
#

#include "libft.h"

int		ft_lstcountbytes(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i += (int)(lst->content_size);
		lst = lst->next;
	}
	return (i);
}
