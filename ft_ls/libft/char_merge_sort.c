/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_merge_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 11:32:35 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/05 17:54:22 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		merge(char *a, char *l, char *r, int count)
{
	int		i;
	int		j;
	int		k;
	int		leftcount;
	int		rightcount;

	leftcount = count / 2;
	rightcount = count - leftcount;
	i = 0;
	j = 0;
	k = 0;
	while (i < leftcount && j < rightcount)
	{
		if (l[i] < r[j])
			a[k++] = l[i++];
		else
			a[k++] = r[j++];
	}
	while (i < leftcount)
		a[k++] = l[i++];
	while (j < rightcount)
		a[k++] = r[j++];
}

void			char_merge_sort(char *a, int n)
{
	int		mid;
	int		i;
	char	*l;
	char	*r;

	i = 0;
	if (n < 2)
		return ;
	mid = n / 2;
	l = (char *)malloc(mid);
	r = (char *)malloc(n - mid);
	while (i < mid)
	{
		l[i] = a[i];
		i++;
	}
	i = mid;
	while (i < n)
	{
		r[i - mid] = a[i];
		i++;
	}
	char_merge_sort(l, mid);
	char_merge_sort(r, (n - mid));
	merge(a, l, r, n);
}
