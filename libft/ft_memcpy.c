#
#
#

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destbis;
	char	*srcbis;
	size_t		i;

	destbis = dest;
	srcbis = (void *)src;
	i = 0;
	while (i < n)
	{
		destbis[i] = srcbis[i];
		i++;
	}
	destbis[i] = '\0';
	return (dest);
}
