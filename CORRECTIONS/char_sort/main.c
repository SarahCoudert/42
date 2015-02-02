#include "includes/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

char **char_sort(char **tab, int count);

int	main()
{
	char		**tab;
	int	i;
	int j;

	j = 0;
	tab = (char**)malloc(sizeof (char *) * 200);
	i = 0;
	srand(time(NULL));
	while (j <= 200)
	{
		tab[j] = (char*)malloc(11);
	while (i < 10)
	{
		if (rand() % 2 == 1)
		tab[j][i] = 'A' + (rand() % 26);
		else
		tab[j][i] = 'a' + (rand() % 26);
		i++;
	}
	tab[j][i] = '\0';
	i = 0;
	j++;
	}
	char_sort(tab, 200);
	i = 0;
	while (i < 200)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
