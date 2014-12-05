#
#
#

#include "libft.h"

int		ft_lstcountelements(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
