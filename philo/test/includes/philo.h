/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:02:20 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/13 14:07:26 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <pthread.h>
# include <SDL.h>
# include <time.h>
# include <pthread.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include <../libft/includes/libft.h>
# define MAX_LIFE		5
# define EAT_T			1
# define REST_T			1
# define THINK_T		1
# define TIMEOUT_S		"Now it is time... To DAAAAAAAANCE!!!"
# define TIMEOUT		60
# define NB_PHILO		7
# define WIDTH_SCREEN	1500
# define HEIGHT_SCREEN	1000
# define COLOR			32
# define RIGHT_BUDDY(x)	((x == 6)? 0 : x - 1)
# define LEFT_BUDDY(x)	((x == 0)? 6 : x + 1)
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
	int					life;
	int					hurt_me;
	int					starve;
}						t_philo;

/*
** pos = philo pos, plate[0] = empty sprite, plate[1] = full sprite 
*/

typedef struct			s_sdl
{
	SDL_Window			*screen;
	SDL_Rect			*pos;
	SDL_Surface			*philo[8];
	SDL_Rect			pos_philo[8];
	SDL_Event			event;
	SDL_Surface			*table;
	SDL_Rect			pos_chop[7];
	SDL_Rect			pos_plate[7];
	SDL_Surface			*plate[2];
	SDL_Surface			*chop[3];
	SDL_Rect			pos_table;
}						t_sdl;

#endif