/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 12:35:02 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/16 11:37:06 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char		**char_sort(char **str, int count)
{
	int		i;
	int		j;
	char	*temp;

	temp = NULL;
	temp = ft_memalloc(200);
	j = 1;
	i = 1;
	while (i < count)
	{
		while (j < count)
		{
			if (ft_strcmp(str[j - 1], str[j]) > 0)
			{
				ft_strcpy(temp, str[j - 1]);
				ft_strcpy(str[j - 1], str[j]);
				ft_strcpy(str[j], temp);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (str);
}