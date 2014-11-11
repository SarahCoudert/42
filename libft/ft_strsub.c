#
#
#
#

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	unsigned int	index;
	int				i;

	i = 0;
	ptr = (char *)&start;
	index = start + (unsigned int)len - 1;
	ptr = malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	while (index != start)
		{
			ptr[i] = s[index];
			index--;
			i++;
		}
		return (ptr);
}
