#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sourc;

	sourc = (void *)src;
	dest = dst;
	if (dest <= sourc)
		return (ft_memcpy(dst, src, n));
	while (n)
	{
		n--;
		dest[n] = sourc[n];
	}
	return (dst);
}
