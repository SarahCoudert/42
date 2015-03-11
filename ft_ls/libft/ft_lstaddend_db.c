#include "libft.h"

void	ft_lstaddend_db(const void *con, size_t con_s, t_lst_db **plst)
{
	t_lst_db		*element;
	t_lst_db		*alst;
	t_lst_db		*ptr;

	alst = *plst;
	ptr = NULL;
	element = ft_lstnew_db(con, con_s);
	if (alst)
	{
		ptr = alst;
		while (alst->next != NULL)
		{
			ptr = alst;
			alst = alst->next;
		}
		if (alst->next == NULL)
		{
			alst->next = element;
			alst->prev = ptr;
		}
	}
	else
		*plst = element;
}
