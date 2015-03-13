

static void		mix(int *tab1, int *tab2, int count1, int count2)
{
	int	i;
	int	j;
	int	k;
	int	*temp;

	i = 0;
	j = 0;
	k = 0;
	temp = malloc(sizeof(tab1[0]) * (count1 + count2));
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

void			mergesort(void *tab, int count, void* sort(void *a, void *b))
{
	if (count == 1)
		return ;
	mergesort(tab, count / 2);
	mergesort(tab + count / 2, (count + 1) / 2);
	mix(tab, tab + count / 2, count / 2, (count + 1) / 2);
}