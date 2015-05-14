/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 14:04:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/14 14:06:35 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int		can_i_eat(t_philo *philo)
{
	philo->timer = 0;
	if (g_glo->life[RIGHT_BUDDY(philo->which)] < g_glo->life[philo->which] ||
		g_glo->life[LEFT_BUDDY(philo->which)] < g_glo->life[philo->which])
		return (NEW_STATE(philo->state));
	else
	{
		if (pthread_mutex_trylock(&g_glo->g_mut_chop[philo->which]) != 0)
			return (NEW_STATE(philo->state));
		else
		{
			if (pthread_mutex_trylock(
				&g_glo->g_mut_chop[RIGHT_BUDDY(philo->which)]) != 0)
			{
				pthread_mutex_unlock(&g_glo->g_mut_chop[philo->which]);
				return (NEW_STATE(philo->state));
			}
			else
			{
				philo->can_eat = 0;
				return (EAT);
			}
		}
	}
	return (NEW_STATE(philo->state));
}

int		change_state(t_philo *philo)
{
	philo->timer++;
	if (philo->state == THINK)
	{
		if (philo->timer >= THINK_T && philo->can_eat == 1)
			philo->state = can_i_eat(philo);
		else
			philo->can_eat = 1;
	}
	else if (philo->state == REST)
	{
		if (philo->timer >= REST_T && philo->can_eat == 1)
			philo->state = can_i_eat(philo);
		else
			philo->can_eat = 1;
	}
	else if (philo->state == EAT)
		philo_must_eat(philo);
	else
		return (-1);
	god_hurt_philo(philo);
	return (1);
}

void	*fn_phi(void *p_data)
{
	t_philo	*philo;
	int		time_now;

	time_now = TIMEOUT;
	philo = (t_philo*)p_data;
	while (g_glo->g_time > 0)
	{
		if (time_now > g_glo->g_time)
		{
			time_now = g_glo->g_time;
			if (change_state(philo) == -1)
				return (NULL);
			g_glo->life[philo->which] = philo->life;
			g_glo->state[philo->which] = philo->state;
		}
		else
			usleep(10000);
	}
	return (NULL);
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
	g_glo->g_time = TIMEOUT;
}

void	*timer(void *p_data)
{
	int		time_now;
	int		time_since;

	time_now = time(NULL);
	(void)p_data;
	g_glo->g_time = TIMEOUT;
	while (g_glo->g_time > 0)
	{
		time_since = time(NULL);
		if (time_now != time_since)
		{
			printf("\ntemps restant : %d\n", g_glo->g_time);
			g_glo->g_time--;
			time_now = time_since;
		}
		if (g_glo->end == 1)
			return (NULL);
		usleep(10000);
	}
	return (NULL);
}
