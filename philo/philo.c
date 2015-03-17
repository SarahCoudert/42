/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 14:04:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/17 18:42:37 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include <pthread.h>
#include "philo.h"

#include <stdio.h>

void	fn_phi(void *p_data)
{
//	static int	i = 0;
	t_philo		*philo;

	philo = (t_philo*)p_data;
	printf("Philosophe numero %d nomme %s\n", philo->wich, philo->name);
}

void	init_tab(char **names)
{
	names[0] = "Cleobule";
	names[1] = "Sade";
	names[2] = "Bacon";
	names[3] = "Grotius";
	names[4] = "Plotin";
	names[5] = "Vico";
	names[6] = "Cousin";
}

int		main(void)
{
	int		i;
	int		ret;
	t_philo	*philo[7];
	char	*names[7];

	ret = 0;
	i = 0;
	while (i < NB_PHILO)
	{
		philo[i] = (t_philo*)malloc(sizeof(t_philo));
		i++;
	}
	i = 0;
	init_tab(names);
	while (i < NB_PHILO)
	{
		philo[i]->wich = i;
		philo[i]->name = names[i];
		ret = pthread_create(&(philo[i])->thread, NULL, fn_phi, (void*)philo[i]);
		i++;
		if (!ret)
			ft_putendl_fd("Error : one or more thread(s) fail to be created");
	}
	i = 0;
	while (i < NB_PHILO)
	{
		pthread_join(philo.thread[i], NULL);
		i++;
	}
		return (0);
}
