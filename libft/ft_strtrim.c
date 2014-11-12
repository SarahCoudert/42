/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:36:58 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/12 13:48:40 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		size;
	int		i;
	int		j;
	char	*temp;

	temp = NULL;
	j = -1;
	size = ft_strlen(s);
	i = -1;
	if (s)
	{
		while (s[++i] == '\n' || s[i] == '\t' || s[i] == ' ' || s[i] == ',')
			size--;
		temp = ft_strdup(s);
		ft_strrev(temp, size + i);
		while (s[++j] == '\n' || s[j] == '\t' || s[j] == ' ' || s[j] == ',')
			size--;
		if (i > 0 && j > 0)
		{
		ft_strrev(temp, size + i + j);
		ft_strncpy((temp + i), temp, size);
		}
		return (temp);
	}
	return (temp);
}
