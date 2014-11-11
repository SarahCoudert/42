#
#
#
#

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t		i;
	
	i = 0;
	ptr = NULL;
	if (s && len)
	{
		ptr = malloc(len + 1 * sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[len + 1] = '\0';
		while (i != len)
		{
			ptr[i] = s[start];
			i++;
			start++;
		}
		return (ptr);
	}
	return (NULL);
}
