#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libft/includes/libft.h"

#define SIZE 100000000
//#define SIZE 600000

void tab_quick_sort_aux(int *tab, int *tab_result, int start, int end) {
	int center;
	int i;
	int small;
	int big;
	if (start == end) {
		tab_result[start] = tab[start];
	} else {
		small = start;
		big = end;
		center = start + (end - start + 1)/2;
		for (i=start; i<=end; i++) {
			if (i != center) {
				if (tab[i] < tab[center]) {
					tab_result[small] = tab[i];
					small++;
				} else {
					tab_result[big] = tab[i];
					big--;
				}
			}
		}
		tab_result[small] = tab[center];
		ft_memcpy(tab + start, tab_result + start, sizeof(int) * (end-start+1));
		if (small > start)
			tab_quick_sort_aux(tab, tab_result, start, small-1);
		if (big < end)
			tab_quick_sort_aux(tab, tab_result, small+1, end);
	}
}

void tab_quick_sort(int *tab, int count) {
	int *tmptab = malloc(sizeof(int) * count);
	tab_quick_sort_aux(tab, tmptab, 0, count-1);
	free(tmptab);
}

int	main()
{
	int	*tab, *tab1, *tab2;
	int	i;
	int j;
	int t1, t2, t3;

	j = 0;
	tab = (int*)malloc(sizeof(int) * SIZE);
	tab1 = (int*)malloc(sizeof(int) * SIZE);
	tab2 = (int*)malloc(sizeof(int) * SIZE);
	i = 0;
	//srand(time(NULL));
	while (j <= SIZE)
	{
		tab[j] = rand();
		j++;
	}
	memcpy(tab1, tab, sizeof(int) * SIZE);
	memcpy(tab2, tab, sizeof(int) * SIZE);
	t1 = time(NULL);
	tab_merge_sort(tab1, SIZE);
	t2 = time(NULL);
	tab_quick_sort(tab2, SIZE);
	t3 = time(NULL);
	while (i < SIZE)
	{
		//printf("%d %d %d", tab[i], tab1[i], tab2[i]);
		if (tab1[i] != tab2[i])
			printf(" NOPE\n");
		//else
		//	printf("\n");
		i++;
	}
	printf("merge sort: %d sec\n", t2-t1);
	printf("quick sort: %d sec\n", t3-t2);
	return (0);
}
