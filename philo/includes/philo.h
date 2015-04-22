/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:02:20 by scoudert          #+#    #+#             */
/*   Updated: 2015/04/22 19:45:37 by scoudert         ###   ########.fr       */
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
# include <unistd.h>
# include <../libft/includes/libft.h>
# define MAX_LIFE		5
# define EAT_T			1
# define REST_T			1
# define THINK_T		1
# define TIMEOUT_S		"Now it is time... To DAAAAAAAANCE!!!"
# define TIMEOUT		20
# define NB_PHILO		7
# define WIDTH_SCREEN	1500
# define HEIGHT_SCREEN	800
# define COLOR			32
# define RIGHT_BUDDY(x)	((x == 0)? NB_PHILO - 1 : x - 1)
# define LEFT_BUDDY(x)	((x == 6)? 0 : x + 1)
# define NEW_STATE(x)	((x == THINK)? REST : THINK)

int			g_time;

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
	struct s_philo		*stru_phi[7];
	SDL_Window			*screen;
	SDL_Rect			*pos;
	SDL_Texture			*philo[7];
	SDL_Event			event;
	SDL_Texture			*table;
	SDL_Texture			*plate[2];
	SDL_Texture			*chop[3];
	SDL_Texture			*name_t[7];
	SDL_Rect			pos_table;
	SDL_Rect			pos_philo[7];
	SDL_Rect			pos_name[7];
	SDL_Renderer		*renderer;
	TTF_Font			*font;
	TTF_Font			*font_m;
	Mix_Music			*music;
}						t_sdl;

void				init_all(t_sdl *sdl);
void				render_table(t_sdl *sdl);
void				render_chops(t_sdl *sdl);
void				render_philo(t_sdl *sdl);
SDL_Rect			create_rect(int x, int y, int h, int w);
void				sprite_init(t_sdl *sdl);
void				render_names(t_sdl *sdl);
void				sdl_renderall(t_sdl *sdl);
void				init_names(t_sdl *sdl);
void				init_pos(t_sdl *sdl);
void				render_time(t_sdl *sdl);
int					event(t_sdl *sdl);
int					timer();
void				destroy_text(t_sdl *sdl);
void				cleanup(t_sdl *sdl);
void				menu(t_sdl *sdl);
void				menu_loop(t_sdl *sdl);
void				end(t_sdl *sdl);
void				render_plates(t_sdl *sdl);

#endif
