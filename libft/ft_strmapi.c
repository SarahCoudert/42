#
#
#
#

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				size;
	unsigned int	i;
	char			*newstr;

	newstr = NULL;
	i = 0;
	size = ft_strlen(s);
	newstr = malloc(size * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while ((int)i < size)
	{
		(*f)(i, newstr[i]);
		i++;
	}
	return (newstr);
}
