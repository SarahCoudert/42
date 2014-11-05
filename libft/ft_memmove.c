#
#
#
#
#

#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	char	*temp;

	temp = (char*)malloc(n * sizeof(char *));
	if (temp == NULL)
	{
		return (NULL);
	}
	temp = ft_strncpy(temp, src, n);
	dest = (void *)ft_strncpy(dest, temp, n);
	free (temp);
	return (dest);
}
