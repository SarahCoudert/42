#
#
#
#

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int len;

	i = 0;
	len = ft_strlen(dest);
	while (i < (ft_strlen(src) + ft_strlen(dest)))
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	return (dest);
}

