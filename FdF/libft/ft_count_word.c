/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 14:05:44 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/16 17:19:51 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Count words in the string 's' who are seperated by the char 'sep'
** like in the ft_strsplit function.
*/
#include "libft.h"

unsigned int	ft_count_word(const char *s, char sep)
{
	int				i;
	unsigned int	counter;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != sep && (i == 0 || s[i - 1] == sep))
			counter++;
		i++;
	}
	return (counter);
}
