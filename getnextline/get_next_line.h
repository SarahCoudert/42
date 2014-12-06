/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 15:30:50 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/27 17:54:41 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE		10
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int		get_next_line(int const fd, char **line);

#endif
