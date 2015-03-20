/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 14:04:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/20 18:36:04 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include <pthread.h>
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mut_chopstick[7];

void	*fn_phi(void *p_data)
{
		t_philo		*philo;
		int chop;

		philo = (t_philo*)p_data;
		chop = rand() % 6;
	if (pthread_mutex_trylock(&mut_chopstick[chop]) == 0)
	{
//		pthread_mutex_lock(&mut_chopstick[philo->which]);
		printf("%s a pris la baguette %d\n", philo->name, chop);
		sleep(3);
		pthread_mutex_unlock(&mut_chopstick[chop]);
		printf("%s a relache la baguette %d\n", philo->name, chop);
	}
	else
		printf("%s voulait prendre la baguette %d, il est frustre\n",philo->name, chop);
	return NULL;
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
	t_philo	*philo[7];
	char	*names[7];

	i = 0;
	while (i < NB_PHILO)
	{
		philo[i] = (t_philo*)malloc(sizeof(t_philo));
		pthread_mutex_init(&mut_chopstick[i], NULL);
		i++;
	}
	i = 0;
	init_tab(names);
	while (i < NB_PHILO)
	{
		philo[i]->which = i;
		philo[i]->name = names[i];
		pthread_create(&(philo[i])->thread, NULL, fn_phi, (void*)philo[i]);
		i++;
	}
	i = 0;
	while (i < NB_PHILO)
	{
		pthread_join(philo[i]->thread, NULL);
		i++;
	}
		return (0);
}