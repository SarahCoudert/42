/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 14:04:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/02 18:07:50 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include <pthread.h>
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t	g_mut_chop[7];
int				g_time;

int				can_i_eat(t_philo *philo)
{
	philo->timer = 0;
	if (pthread_mutex_trylock(&g_mut_chop[philo->which]) != 0)
	{
		printf("%s n'a pas reussi a lock sa propre baguette %d\n",
			philo->name, philo->which);
		return (NEW_STATE(philo->state));
	}
	else
	{
		printf("%s a reussi a prendre sa baguette %d\n",
			philo->name, philo->which);
		if (pthread_mutex_trylock(&g_mut_chop[RIGHT_BUDDY(philo->which)]) != 0)
		{
			pthread_mutex_unlock(&g_mut_chop[philo->which]);
			printf("%s n'a pas reussi a lock la baguette %d de son voisin\n",
				philo->name, philo->which);
			return (NEW_STATE(philo->state));
		}
		else
		{
			printf("%s a reussi a lock la baguette %d de son voisin\n",
				philo->name, RIGHT_BUDDY(philo->which));
			return (EAT);
		}
	}
	return (-1);
}

int			change_state(t_philo *philo)
{
	if (philo->state == THINK)
	{
		if (philo->timer == THINK_T)
			philo->state = can_i_eat(philo);
		else
			philo->timer++;
	}
	else if (philo->state == REST)
	{
		if (philo->timer == REST_T)
			philo->state = can_i_eat(philo);
		else
			philo->timer++;
	}
	else if (philo->state == EAT)
	{
		if (philo->timer == EAT_T)
		{
			pthread_mutex_unlock(&g_mut_chop[philo->which]);
			pthread_mutex_unlock(&g_mut_chop[RIGHT_BUDDY(philo->which)]);
			philo->state = REST;
		}
		else
			philo->timer++;
	}
	else
		return (-1);
	if (philo->state == 0)
		printf("%s se repose.\n", philo->name);
	else if (philo->state == 1)
		printf("%s reflechis.\n", philo->name);
	else if (philo->state == 2)
		printf("%s mange.\n", philo->name);
	return (1);
}

void		*fn_phi(void *p_data)
{
	t_philo	*philo;
	int		time_now;

	time_now = TIMEOUT;
	philo = (t_philo*)p_data;
	while (g_time > 0)
	{
		if (time_now > g_time)
		{
			time_now = g_time;
			if (change_state(philo) == -1)
				return NULL;
		}
		else
			usleep(10000);
	}
	return NULL;
}

void		init_tab(char **names)
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

void		*timer(void *p_data)
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

int				main(void)
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
		pthread_mutex_init(&g_mut_chop[i], NULL);
		philo[i]->which = i;
		philo[i]->name = names[i];
		philo[i]->state = THINK;
		philo[i]->timer = THINK_T;
		pthread_create(&(philo[i])->thread, NULL, fn_phi, (void*)philo[i]);
		i++;
	}
	pthread_create(&timer_t, NULL, timer, NULL);
	i = -1;
		pthread_join(timer_t, NULL);
	while (++i < NB_PHILO)
		pthread_join(philo[i]->thread, NULL);
	return (0);
}
