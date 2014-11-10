/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:56:22 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/10 17:19:04 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1bis;
	const char	*s2bis;
	size_t		i;

	s1bis = s1;
	s2bis = s2;
	i = 0;
	if (!s1 && !s2 && i == 0)
		return (0);
	while (s1bis[i] == s2bis[i] && s2bis[i] && s1bis[i])
	{
		i++;
		if (!s1bis[i] && !s2bis[i])
			return (0);
		else
			return (s1bis[i] - s2bis[i]);
	}
}
