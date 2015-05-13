/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 14:04:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/11 13:47:26 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "philo.h"
#include <stdio.h>

int				can_i_eat(t_philo *philo)
{
	int		time;
	int		lock0;
	int		lock1;

	philo->timer = 0;
	time = g_glo->g_time;
	while (time == g_glo->g_time)
	{
			lock0 = pthread_mutex_trylock(&g_glo->g_mut_chop[philo->which]);
			lock1 = pthread_mutex_trylock(&g_glo->g_mut_chop[RIGHT_BUDDY(philo->which)]);
		if (lock0 == 0 && lock1 == 0)
		{
			g_glo->g_bool_chop[philo->which] = 1;
			g_glo->g_bool_chop[RIGHT_BUDDY(philo->which)] = 1;
			return (EAT);
		}
		// usleep(1000);
		if (lock0 == 0)
		{
			pthread_mutex_unlock(&g_glo->g_mut_chop[philo->which]);
			g_glo->g_bool_chop[philo->which] = 1;
		}
		if (lock1 == 0)
		{
			pthread_mutex_unlock(&g_glo->g_mut_chop[RIGHT_BUDDY(philo->which)]);
			g_glo->g_bool_chop[RIGHT_BUDDY(philo->which)] = 1;
		}
	}
	return (NEW_STATE(philo->state));
}

int			change_state(t_philo *philo)
{
	if (philo->state == THINK)
	{
		if (philo->timer >= THINK_T && philo->can_eat == 1)
			philo->state = can_i_eat(philo);
		else
		{
			philo->timer++;
			philo->can_eat = 1;
		}
	}
	else if (philo->state == REST)
	{
		if (philo->timer >= REST_T && philo->can_eat == 1)
			philo->state = can_i_eat(philo);
		else
		{
			philo->timer++;
			philo->can_eat = 1;
		}
	}
	else if (philo->state == EAT)
	{
		if (philo->timer >= EAT_T)
		{
			g_glo->g_bool_chop[philo->which] = 0;
			g_glo->g_bool_chop[RIGHT_BUDDY(philo->which)] = 0;
			pthread_mutex_unlock(&g_glo->g_mut_chop[philo->which]);
			pthread_mutex_unlock(&g_glo->g_mut_chop[RIGHT_BUDDY(philo->which)]);
			philo->state = REST;
			philo->life = MAX_LIFE;
			philo->can_eat = 0;
		}
		else
			philo->timer++;
	}
	else
		return (-1);
	if (philo->state == REST)
		printf("%s se repose.\n", philo->name);
	else if (philo->state == THINK)
		printf("%s reflechis.\n", philo->name);

	if (philo->state == EAT)
		printf("\t\t\t\t\t%s mange. \n", philo->name);
	if (philo->state != EAT && philo->hurt_me != 0)
	{
		philo->life--;
	}
	philo->hurt_me = 1;
	printf("\t%s a %d de vie\n", philo->name, philo->life);
	if (philo->life <= 0)
	{
		printf("\n\n\t\t\t\t%s est mort\n\n", philo->name);
		g_glo->state[philo->which] = DEAD;
		g_glo->end = 1;
		return (-1);
	}
	if (g_glo->end == 1)
		return (-1);
	return (1);
}

void		*fn_phi(void *p_data)
{
	t_philo	*philo;
	int		time_now;

	time_now = TIMEOUT;
	philo = (t_philo*)p_data;
	while (g_glo->g_time <= 0)
	{
		usleep(5000);
	}
	while (g_glo->g_time > 0)
	{
		g_glo->life[philo->which] = philo->life;
		g_glo->state[philo->which] = philo->state;
		if (time_now > g_glo->g_time)
		{
			time_now = g_glo->g_time;
			if (change_state(philo) == -1)
				return (NULL);
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
	g_glo->g_time = TIMEOUT;
}

void		*timer(void *p_data)
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

// penser a supprimer les threads

int				main(int ac, char **av)
{
	int			i;
	pthread_t	timer_t;
	t_sdl		sdl;
	pthread_t	sdl_t;

	(void)ac;
	(void)**av;
	i = -1;
	g_glo = (t_global*)malloc(sizeof(t_global));
	g_glo->end = 0;
	init_begin(&sdl);
	if (EAT_T <= 0 || REST_T <= 0 || THINK_T <= 0 ||
		TIMEOUT <= 0 || MAX_LIFE <= 0)
	{
		ft_putendl("Error in parameters");
		exit (-1);
	}
	pthread_create(&timer_t, NULL, timer, NULL);
	pthread_create(&sdl_t, NULL, main_2, (void*)&sdl);
	i = -1;
	pthread_join(sdl_t, NULL);
	while (++i < NB_PHILO)
		pthread_join(sdl.stru_phi[i]->thread, NULL);
	pthread_join(timer_t, NULL);
	return (0);
}
