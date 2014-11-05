#
#
#
#

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	int		i;

	i = ft_strlen(s);
	newstr = malloc(i * sizeof(char));
	if (newstr == NULL)
	{
		return (NULL);
	}
	ft_strcpy(newstr, s);
	return (newstr);
}
