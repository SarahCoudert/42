#
#
#

<<<<<<< HEAD
#include "includes/libft.h"
=======
#include "libft.h"
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst && f)
	{
		(*f)(lst);
		lst = lst->next;
	}
}
