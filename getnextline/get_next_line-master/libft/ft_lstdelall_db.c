#include "includes/libft.h"

void	ft_lstdelall_db(t_lst_db **lst)
{
	while (lst && (*lst) && (*lst)->prev != NULL)
	{
		(*lst)->prev->next = *lst;
		*lst = (*lst)->prev;
	}
	while (lst && (*lst) && (*lst)->next != NULL)
	{
		if ((*lst)->content != NULL)
		{
			ft_memdel(&((*lst)->content));
			(*lst)->content_size = 0;
		}
		*lst = (*lst)->next;
		ft_memdel((void**)&(*lst)->prev);
	}
	if (lst)
		ft_memdel((void**)lst);
}