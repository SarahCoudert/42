/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:02:20 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/20 18:10:59 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "libft.h"
# include <stdlib.h>
# define MAX_LIFE		100
# define EAT_T			1
# define REST_T			5
# define THINK_T		5
# define TIMEOUT_S			"Now it is time... To DAAAAAAAANCE!!!"
# define TIMEOUT		100
# define NB_PHILO		7
# define RightPhilo(x) ((x == 0)? NB_PHILO-1 : x-1)

typedef enum			e_name
{
	CLEOBULE,
	SADE,
	BACON,
	GROTIUS,
	PLOTIN,
	VICO,
	COUSIN
}						t_name;

typedef enum			e_state
{
	REST,
	THINK,
	EAT,
	STARVE
}						t_state;

typedef struct			s_philo
{
	pthread_t			thread;
	char				*name;
	int					which;
	int					state;
}						t_philo;

#endif
