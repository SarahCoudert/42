#
#
#

#include "libft.h"
#include <stdlib.h>

/*
** Transforme un tableau de char contenant des chiffres separes par des espaces
** en un tableau d'int.
*/

int		*ft_strtoint(const char *s)
{
	int		*result;
	char	**split;
	int		words;
	int		i;

	i = 0;
	words = ft_count_word(s, ' ');
	result = NULL;
	result = (int *) malloc(sizeof(int) * words);
	split = ft_strsplit(s, ' ');
	while (i < words)
	{
		result[i] = atoi(split[i]);
		i++;
	}
	return (result);
}
