/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 13:05:39 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/05/20 15:02:33 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_must_eat(t_philo *philo)
{
	if (philo->timer >= EAT_T)
	{
		g_glo->g_chop[philo->which] = 0;
		g_glo->g_chop[RIGHT_BUDDY(philo->which)] = 0;
		pthread_mutex_unlock(&g_glo->g_mut_chop[philo->which]);
		pthread_mutex_unlock(&g_glo->g_mut_chop[RIGHT_BUDDY(philo->which)]);
		philo->state = REST;
		philo->timer = 0;
		philo->life = MAX_LIFE + 1;
	}
}

int		god_hurt_philo(t_philo *philo)
{
	if (philo->state != EAT && philo->hurt_me != 0)
		philo->life--;
	philo->hurt_me = 1;
	if (philo->life <= 0)
	{
		g_glo->state[philo->which] = DEAD;
		g_glo->end = 1;
		return (-1);
	}
	if (g_glo->end == 1)
		return (-1);
	return (1);
}

int		main(int ac, char **av)
{
	pthread_t	timer_t;
	t_sdl		sdl;

	(void)ac;
	(void)**av;
	g_glo = (t_global*)malloc(sizeof(t_global));
	g_glo->g_time = TIMEOUT;
	g_glo->end = -1;
	g_glo->pause = 0;
	init_begin(&sdl);
	if (EAT_T <= 0 || REST_T <= 0 || THINK_T <= 0 || TIMEOUT <= 0 ||
		MAX_LIFE <= 0 || NB_PHILO < 1 || NB_PHILO > 7)
		ft_put_error("Error in parameters", 0, 1);
	pthread_create(&timer_t, NULL, timer, NULL);
	main_2(&sdl);
	return (0);
}
