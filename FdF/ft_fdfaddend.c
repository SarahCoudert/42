#
#
#
#

#include "fdf.h"
#include <stdlib.h>
#include "libft.h"

static t_fdf	*fdfnew(int x, int z, int y)
{
	t_fdf	*ret;

	ret = (t_fdf*)ft_strnew(sizeof(t_fdf));
	if (ret == NULL)
		return (NULL);
	if (x && z && y)
	{
		ret->x = x;
		ret->y = y;
		ret->z = z;
	}
	return (ret);
}

void			ft_fdfaddend(int x, int y, int z, t_fdf **lst)
{
	t_fdf		*element;
	t_fdf		*alst;

	alst = *lst;
	element = fdfnew(x, z, y);
	/*	ft_putnbr(element->x);
		putn();
		ft_putnbr(element->y);
		putn();
		ft_putnbr(element->z);
		putn();*/
	if (alst)
	{
		while (alst->next != NULL)
			alst = alst->next;
		if (alst->next == NULL)
		alst->next = element;
	}
	else
		*lst = element;
}
