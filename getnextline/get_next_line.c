/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 15:30:44 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/21 18:06:57 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

int			get_next_line(int const fd, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (fd < 0)
		return (-1);
	if (line == NULL || *line == NULL)
		return (-1);
	while (i != BUFFSIZE)
	{
		
	}
}
