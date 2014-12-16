/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:34:55 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/15 17:32:51 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && s1[i] != '\0' && i < n - 1)
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
