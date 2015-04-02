/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:02:20 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/02 16:14:38 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <pthread.h>
# include "../libft/includes/libft.h"
# include "../SDL/include/SDL/SDL_mixer.h"
# include "../SDL/include/SDL/SDL_ttf.h"
# include "../SDL/include/SDL/SDL_mixer.h"
# include "../SDL/include/SDL/SDL.h"
# define MAX_LIFE		100
# define EAT_T			2
# define REST_T			2
# define THINK_T		2
# define TIMEOUT_S		"Now it is time... To DAAAAAAAANCE!!!"
# define TIMEOUT		100
# define NB_PHILO		7
# define WIDTH_SCREEN	640
# define HEIGHT_SCREEN	480
# define COLOR			32
# define RIGHT_BUDDY(x)	((x == NB_PHILO)? 0 : x + 1)
# define NEW_STATE(x)	((x == THINK)? REST : THINK)

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
	int					timer;
}						t_philo;

typedef struct		s_sdl
{
	SDL_Surface		*screen;
	SDL_Rect		*pos;
	SDL_Surface		*philo[8];
	SDL_Rect		pos_philo[8];
	SDL_Event		event;
}					t_sdl;

#endif
