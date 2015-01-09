/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 15:08:13 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/09 14:48:17 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			**ft_strsplit(const char *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		j;
	size_t		len;

	if (!s || !c)
		return (0);
	ret = ft_memalloc((ft_count_word(s, c) + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			ret[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	ret[j] = NULL;
	return (ret);
}
