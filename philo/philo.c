/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 14:04:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/24 17:39:51 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./libft/includes/libft.h"
#include <pthread.h>
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t g_mut_chopstick[7];
int	g_time;

void	change_state(t_philo *philo)
{
	if (philo->state == THINK)
	{
		if (philo->timer == THINK_T)
		{
			philo->timer = 0;
			philo->state = (can_i_eat(philo));
		}
		else
			philo->timer++;
	}
	else if (philo->state == REST)
	{
		if (philo->timer == REST_T)
		{
			philo->timer = 0;
			philo->state = can_i_eat(philo);
		}
		else
			philo->timer++;
	}
	else if ()

}

void	*fn_phi(void *p_data)
{
	t_philo		*philo;
	int chop;
	int time_now;

	time_now = TIMEOUT;
	philo = (t_philo*)p_data;
	while (g_time > 0)
	{
		if (time_now > g_time)
		{
			time_now = g_time;
			change_state(philo);
		}
		else
			usleep(10000);
	}
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
	g_time = TIMEOUT;
}

void	*timer(void *p_data)
{
	int		time_now;
	int		time_since;

	time_now = time(NULL);
	(void)p_data;
	while (g_time > 0)
	{
		time_since = time(NULL);
		if (time_now != time_since)
		{
			g_time--;
			printf("\ntemps restant : %d\n", g_time);
			time_now = time_since;
		}
		usleep(10000);
	}
	return (NULL);
}

int		main(void)
{
	int			i;
	t_philo		*philo[7];
	char		*names[7];
	pthread_t	timer_t;

	init_tab(names);
	i = 0;
	while (i < NB_PHILO)
	{
		philo[i] = (t_philo*)malloc(sizeof(t_philo));
		pthread_mutex_init(&g_mut_chopstick[i], NULL);
		philo[i]->which = i;
		philo[i]->name = names[i];
		philo[i]->state = THINK;
		philo[i]->timer = 0;
		pthread_create(&(philo[i])->thread, NULL, fn_phi, (void*)philo[i]);
		i++;
	}
	pthread_create(&timer_t, NULL, timer, NULL);
	i = -1;
	while (++i < NB_PHILO)
		pthread_join(philo[i]->thread, NULL);
	pthread_join(timer_t, NULL);
	return (0);
}
