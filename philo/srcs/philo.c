/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 14:04:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/05 14:32:23 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//je suis un poney
#include "../libft/includes/libft.h"
#include <pthread.h>
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t	g_mut_chop[7];
int				g_time;
int 			g_starve[7];

int		can_i_eat(t_philo *philo)
{
	static int impair = 0;
	static int pair   = 0;

	if (philo->which % 2 == 0)
	{
		if (philo->life <= 5 && pair < 1)
		{
			pair++;
			while (pthread_mutex_trylock(&g_mut_chop[RIGHT_BUDDY(philo->which)]) != 0)
				;
			pthread_mutex_lock(&g_mut_chop[RIGHT_BUDDY(philo->which)]);
			while (pthread_mutex_trylock(&g_mut_chop[philo->which]) != 0)
				;
			pthread_mutex_lock(&g_mut_chop[philo->which]);
			pair--;
			return (EAT);
		}
		else
		{
			if ((pthread_mutex_trylock(&g_mut_chop[RIGHT_BUDDY(philo->which)])) != 0)
				return (1);
			if ((pthread_mutex_trylock(&g_mut_chop[philo->which])) != 0)
				return (1);
		}
	}
	else
	{
		if (philo->life <= 5 && impair < 1)
		{
			impair++;
			while ((pthread_mutex_trylock(&g_mut_chop[philo->which])) != 0)
				;
			pthread_mutex_lock(&g_mut_chop[philo->which]);
			while ((pthread_mutex_trylock(&g_mut_chop[RIGHT_BUDDY(philo->which)])) != 0)
				;
			pthread_mutex_lock(&g_mut_chop[RIGHT_BUDDY(philo->which)]);
			impair--;
			return (EAT);
		}
		else
		{
			if ((pthread_mutex_trylock(&g_mut_chop[philo->which])) != 0)
				return (1);
			if ((pthread_mutex_trylock(&g_mut_chop[RIGHT_BUDDY(philo->which)])) != 0)
				return (1);
		}

	}
	return (0);
}

int			change_state(t_philo *philo)
{
/*	if (philo->life <= 3 && ((g_starve[LEFT_BUDDY(philo->which)]) == 0))
	{
		philo->starve = 1;
		g_starve[philo->which] = 1;
	}
	if (philo->life > 3)
		g_starve[philo->which] = 0;
	if ((g_starve[LEFT_BUDDY(philo->which)]) == 1)
	{
		printf ("%s est force de se mettre au repose\n", philo->name);
		philo->state = REST;
	}
	if ((g_starve[RIGHT_BUDDY(philo->which)]) == 1)
	{
		printf("%s est force de se mettre au repose\n", philo->name);
		philo->state = REST;
	}*/
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
			printf ("%s mange", philo->name);
			philo->life = MAX_LIFE;
			philo->starve = 0;
		}
		else
			philo->timer++;
	}
	else
		return (-1);
	if (philo->state != EAT && philo->hurt_me != 0)
		philo->life--;
	philo->hurt_me = 1;
	printf("\t%s a %d de vie\n", philo->name, philo->life);
	if (philo->life == 0)
	{
		printf("\n\n\t\t\t\t%s est mort\n\n", philo->name);
		return (-1);
	}
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
				exit (0);
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
			printf("\ntemps restant : %d\n", g_time);
			g_time--;
			time_now = time_since;
		}
		usleep(10000);
	}
	return (NULL);
}

void			init_philos(t_sdl *sdl, char **names)
{
	int		i;

	i = 0;
	while (i < NB_PHILO)
	{
		sdl->stru_phi[i] = (t_philo*)malloc(sizeof(t_philo));
		pthread_mutex_init(&g_mut_chop[i], NULL);
		sdl->stru_phi[i]->which = i;
		sdl->stru_phi[i]->name = names[i];
		sdl->stru_phi[i]->state = THINK;
		sdl->stru_phi[i]->timer = THINK_T;
		sdl->stru_phi[i]->life = MAX_LIFE;
		sdl->stru_phi[i]->hurt_me = 0;
		pthread_create(&(sdl->stru_phi[i])->thread, NULL, fn_phi,
			(void*)sdl->stru_phi[i]);
		i++;
	}
}

int				main(int ac, char **av)
{
	(void)ac;
	(void)**av;
	int			i;
	char		*names[7];
	pthread_t	timer_t;
	t_sdl		sdl;

	init_tab(names);
	init_philos(&sdl, names);
	pthread_create(&timer_t, NULL, timer, NULL);
	i = -1;
		pthread_join(timer_t, NULL);
	while (++i < NB_PHILO)
		pthread_join(sdl.stru_phi[i]->thread, NULL);
	return (0);
}