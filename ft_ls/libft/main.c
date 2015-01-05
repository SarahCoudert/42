#include "includes/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int *MergeSort(int *tab, int count);

int	main()
{
	int	*tab;
	int	i;
	int j;

	j = 0;
	tab = (int*)malloc(sizeof(int) * 999999);
	i = 0;
	srand(time(NULL));
	while (j <= 999999)
	{
		tab[j] = rand();
		j++;
	}
	tabtab_merge_sort(tab, 999999);
	while (i < 999999)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		if (tab[i] > tab[i+1] && i + i <= 999999)
		ft_putendl("NOPE");
		i++;
	}
	return (0);
}
