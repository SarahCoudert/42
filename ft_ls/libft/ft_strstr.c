#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)s1;
	j = 0;
	if (s2[j] == '\0')
		return (str);
	while (*str != '\0')
	{
		while (str[j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return (str);
		}
		str++;
		j = 0;
	}
	return (NULL);
}
