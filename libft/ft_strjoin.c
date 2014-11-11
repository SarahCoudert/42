#
#
#
#

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*newstr;
	int		ends1;
	int		ends2;

	ends1 = ft_strlen(s1);
	ends2 = ft_strlen(s2);
	size = ends1 + ends2;
	if (s1 && s2)
	{
	newstr = malloc((size + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	newstr[size + 1] = '\0';
	while (ends1 > 0)
	{
		
	}
	newstr = ft_strcat(newstr, (char *)s2);
	return (newstr);
	}
}

/*int main()
{
	char s1[] = "bonjour je suis Bertrand";
	char s2[] = " je suis gentil";
	char *str;

	str = ft_strjoin(s1, s2);
	ft_putstr(str);
	return (0);
}*/
