#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int isSubstring(const char *small, int smallLength, const char *big, int bigLength)
{
	int i;
	int	k;
	int good;

	i = 0;
	k = 0;
	while (i < bigLength)
	{
		// la petite chaine se trouve-t-elle en position i dans la grande ?
		good = 1;
		while (k < smallLength)
		{
			if (i + k >= bigLength || small[k] != big[i + k])
			{
				// non, la petite chaine n'est pas en position i dans la grande
				good = 0;
			}
			k++;
		}
		if (good)
		{
			// la petite chaine se trouve en position i dans la grande
			return (1);
		}
		i++;
	}
	// la petite chaine ne se trouve en aucune position dans la grande
	return (0);
}

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(int argc, char *argv[])
{
	int		start;
	int		end;
	int		len;
	int		k;
	int		bestLength;
	int		bestStart;
	int		triedLength;
	int		subStringInAll;

	start = 0;
	end = 0;
	len = 0;
	k = 2;
	bestLength = 0;
	bestStart = 0;
	triedLength = 0;
	subStringInAll = 0;
	if (argc < 2)
	{
		write (1, "\n", 1);
		return (1);
	}
	len = ft_strlen(argv[1]);
	while (start < len)
	{
		end = start;
		while (end < len)
		{// on teste la sous-chaine de argv[1] qui va de start a end
			triedLength = end - start + 1;
			subStringInAll = 1;
			while (k < argc)
			{
				// tester si la chaine argv[k] contient la sous-chaine de argv[1] en cours de test
				if (!isSubstring(argv[1] + start, triedLength, argv[k], ft_strlen(argv[k])))
				{
					subStringInAll = 0;
				}
				k++;
			}
			if (subStringInAll)
			{
				// la sous-chaine en cours de test est "bonne" : elle est presente dans chacune des chaines.
				// Mais est-elle meilleure que la meilleure connue jusqu'a maintenant ?
				if (triedLength > bestLength)
				{
					bestLength = triedLength;
					bestStart = start;
				}
			}
			end++;
		}
		start++;
	}
	write(1, argv[1] + bestStart, bestLength);
	write(1, "\n", 1);
	return 0;
}
