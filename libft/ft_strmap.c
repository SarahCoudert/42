#
#
#
#
#

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	int		i;
	char	*newstr;

	newstr = NULL;
	i = 0;
	size = ft_strlen(s);
	newstr = malloc(size * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (i < size)
	{
		(*f)(newstr[i]);
		i++;
	}
	return (newstr);
}
