#
#
#
#
#include "includes/libft.h"
#include <stdlib.h>

<<<<<<< HEAD
static void		mix(int *tab1, int *tab2, int count1, int count2)
{
	int	i;
	int	j;
	int	k;
	int	*temp;

	i = 0;
	j = 0;
	k = 0;
	temp = (int *)malloc(sizeof(int) * (count1 + count2));
	while ((j < count1) && (k < count2))
	{
		while ((j < count1) && (*(tab1 + j) <= *(tab2 + k)))
			*(temp + i++) = *(tab1 + j++);
		if (j < count1)
			while ((k < count2) && (*(tab2 + k) <= *(tab1 + j)))
				*(temp + i++) = *(tab2 + k++);
	}
	ft_memcpy(temp + i, tab1 + j, (count1 - j) * sizeof(int));
	ft_memcpy(tab1, temp, count1 * sizeof(int));
	ft_memcpy(temp + i, tab2 + k, (count2 - k) * sizeof(int));
	ft_memcpy(tab2, temp + count1, count2 * sizeof(int));
	free(temp);
}

void 			merge_sort(int *tab, int count)
{
	if(count == 1)
		return ;
	merge_sort(tab, count / 2);
	merge_sort(tab + count / 2, (count + 1) / 2);
	mix(tab, tab + count / 2, count / 2, (count + 1) / 2);
=======
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
>>>>>>> ca84cb40e6cd6f18b91b5dd6141b13d8b2336d85
}
