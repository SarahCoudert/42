#include "includes/libft.h"

int	main()
{
	int	tab[] = {30, 5, 1, 25, 76, 96, 1, 2};
	int	i;
	
	i = 0;
	tab_merge_sort(tab);
	while (i < 7)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
	}
	return (0);
}
