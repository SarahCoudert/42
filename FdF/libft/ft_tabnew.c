#
#
#

#include "libft.h"
#include <stdlib.h>

/*
**Prend une taille et alloue un double tableau tout en mettant la derniere
** case a NULL
*/

void	**ft_tabnew(int size)
{
	void	**res;

	res = NULL;
	res = (void**)malloc(size + 1);
	if (res == NULL)
		return (NULL);
	res[size + 1] = NULL;
	return (res);
}
