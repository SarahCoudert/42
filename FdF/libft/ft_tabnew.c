/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 14:42:46 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/22 16:58:08 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	**ft_tabnew(int size)
{
	char	**res;

	if ((res = (void *)ft_strnew(size + (sizeof(void *)))) == NULL)
		return (NULL);
	res[size + 1] = NULL;
	return ((void**)res);
}
