#
#
#
#
#include "includes/libft.h"
#include <stdlib.h>

static void		tab_merge(int *left, int *right, int *tab)
{
	size_t   i;
	size_t   k;
	size_t   j;
	size_t   llen;
	size_t   rlen;

	j = 0;
	i = j;
	k = i;
	llen = sizeof(left) / sizeof(left[0]);
	rlen = sizeof(right) / sizeof(right[0]);
	while (i < llen || j < rlen)
	{
		if (left[i] <= right[j])
		{
			tab[k] = left[i];
			i++;
		}
		else if (right[j] <= left[i])
		{
			tab[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < llen)
	{
		tab[k] = left[i];
		i++;
		k++;
	}
	while (j < rlen)
	{
		tab[k] = right[j];
		j++;
		k++;
	}
}

int       *tab_merge_sort(int *tab)
{
	size_t n;
	size_t mid;
	int  *left;
	int  *right;
	size_t  i;

	i = -1;
	n = sizeof(tab) / sizeof(tab[0]);
	mid = n / 2;
	if (n < 2)
		return (tab);
	left = malloc(mid * sizeof(int));
	right = malloc((n - mid) * sizeof(int));
	while (++i < mid - 1)
		left[i] = tab[i];
	while (++i < n - 1)
		right[i] = tab[i];
	tab_merge_sort(left);
	tab_merge_sort(right);
	tab_merge(left, right, tab);
	return (tab);
}
