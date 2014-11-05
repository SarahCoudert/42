#
#
#
#
#

#include "libft.h"

char	*ft_strncat(char *dest, const char *str, size_t n)
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
