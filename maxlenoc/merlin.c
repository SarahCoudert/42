
#include <unistd.h>

int		match(char *str, char *fdn, int n)
{
	int		i, j;

	i = 0;
	while (fdn[i] != '\0')
	{
		j = 0;
		while (str[j] == fdn[j + i])
		{
			if (j == n)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	maxlen(char *str, char **tab)
{
	int		n;
	int		m;
	int		i;
	int		k;
	int		l;

	l = 0;
	k = 0;
	n = 0;
	m = 0;
	while (tab[i] != NULL)
	{
		if (match(str, tab[i], n) == 1)
			
		i++;
	}
	
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		maxlen(argv[1], *(argv + 1));
	}
	write(1, "\n", 1);
	return (0);
}
