#
#
#
#
#

#include "libft.h"
#include <stdlib.h>

static int		countnbofwords(const char *s, char c);
static int		*ft_wordssize(const char *s, char c, int words, int *wordsize);


char	**ft_strsplit(const char *s, char c)
{
	int		i;
	char	*tab;
	int		*wordssize;
	int		numofwords;

	wordssize = 0;
	numofwords = 0;
	tab = NULL;
	i = 0;
	if (s && c)
	{
		numofwords = countnbofwords(s, c);
		if (numofwords > 0)
			wordssize = malloc(numofwords * sizeof(char *));
		if (wordssize == NULL)
			return (NULL);
		tab = (char **)malloc(numofwords * );
		wordssize = ft_wordssize(s, c, numofwords, wordssize);
	}
}

static int		countnbofwords(const char *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			counter++;
			i++;
		}
		else
			i++;
	}
	return (counter);
}

static int		*ft_wordssize(const char *s, char c, int words, int *wordsize)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			while (s[i] != c)
			{
				j++;
				i++;
			}
			wordsize[k] = j;
			j = 0;
			k++;
		}
		else
			i++;
	}
	return (wordsize);
}
