#
#
#
#

#include "includes/libft.h"
#include <stdlib.h>

char		**char_sort(char **str, int count)
{
	int		i;
	int		j;
	char	*temp;
	char	**s_return;

	s_return = str;
	temp = NULL;
	temp = ft_memalloc(200);
	j = 1;
	i = 1;
	while (i < count)
	{
		while (j < count)
		{
			if (ft_strcmp(str[j - 1], str[j]) > 0)
			{
				ft_strcpy(temp, str[j - 1]);
				ft_strcpy(str[j - 1], str[j]);
				ft_strcpy(str[j], temp);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (s_return);
}
