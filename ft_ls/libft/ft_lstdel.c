#
#
#

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{

	if (alst && *alst)
	{
		if ((*alst)->next == NULL)
			ft_lstdelone(alst, del);
		else
		{
			ft_lstdel(&((*alst)->next), del);
			ft_lstdelone(alst, del);
		}
	}
}
