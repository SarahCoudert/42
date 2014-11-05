#
#
#
#
#

#include "libft.h"

char	*strcat(char *dest, const char *str)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(dest);
	while (i < ft_strlen(dest) + ft_strlen(str))
	{
		dest[i] = str[j];
		i++;
		j++;
	}
	return (dest);
}
