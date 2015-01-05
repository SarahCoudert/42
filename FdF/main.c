/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:13:30 by scoudert          #+#    #+#             */
/*   Updated: 2014/12/22 15:10:22 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/get_next_line.h"
#include "libft/includes/libft.h"
#include <fcntl.h>

int		main(int argc, const char *argv[])
{
	int		fd;
	int		gnl_status;
	char	**s;
	t_list	*lst;

	*s = NULL;
	gnl_status = 1;
	fd = 0;
	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	while (gnl_status != 0)
	{
		gnl_status = get_next_line(fd, s);
		ft_strtolst(*s, ft_strlen(*s), &lst);
	}
	return (0);
}
