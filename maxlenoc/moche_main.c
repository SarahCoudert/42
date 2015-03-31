#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int isSubstring(const char *small, int smallLength, const char *big, int bigLength)
{
	int	i;
	int	k;
	int	good;

	k = 0;
	i = 0;
	while (i < bigLength)
	{
		good = 1;
		while (k++ < smallLength)
		{ 
			if (i + k >= bigLength || small[k] != big[i + k])
			{
				good = 0;
			}
//			k++;
		}
		if (good)
		{
			return 1;
		}
		i++;
	}
	return (0);
}

int		ft_strlen(char *s)
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
	int		best_len;
	int		best_start;
	int		tried_len;
	int		sub_string_all;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	len = ft_strlen(argv[1]);
	for (start=0; start<len; start++)
	{
		for (end=start; end<len; end++)
		{
			// on teste la sous-chaine de argv[1] qui va de start a end
			tried_len = end - start + 1;
			sub_string_all = 1;
			for (k=2; k<argc; k++)
			{
				// tester si la chaine argv[k] contient la sous-chaine de argv[1] en cours de test
				if (! isSubstring(argv[1]+start, tried_len, argv[k], ft_strlen(argv[k])))
				{
					sub_string_all = 0;
				}
			}
			if (sub_string_all)
			{
				// la sous-chaine en cours de test est "bonne" : elle est presente dans chacune des chaines.
				// Mais est-elle meilleure que la meilleure connue jusqu'a maintenant ?
				if (tried_len > best_len)
				{
					best_len = tried_len;
					best_start = start;
				}
			}
		}
	}
	write(1, argv[1]+best_start, best_len);
	write(1, "\n", 1);
	return 0;
}
