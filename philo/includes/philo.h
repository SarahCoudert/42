/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:02:20 by scoudert          #+#    #+#             */
/*   Updated: 2015/05/05 11:26:32 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <pthread.h>
# include <SDL2/SDL.h>
# include <time.h>
# include <pthread.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_mixer.h>
# include <unistd.h>
# include <../libft/includes/libft.h>
# define MAX_LIFE		40
# define EAT_T			1
# define REST_T			1
# define THINK_T		1
# define TIMEOUT_S		"Now it is time... To DAAAAAAAANCE!!!"
# define TIMEOUT		10
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
	int					*chop_state[7];
	SDL_Window			*screen;
	SDL_Rect			*pos;
	SDL_Rect			*life_r[7];
	SDL_Texture			*philo[7];
	SDL_Event			event;
	SDL_Texture			*table;
	SDL_Texture			*plate[2];
	SDL_Texture			*chop[3];
	SDL_Texture			*name_t[7];
	SDL_Rect			pos_table;
	SDL_Rect			pos_philo[7];
	SDL_Rect			pos_name[7];
	SDL_Rect			pos_plate[7];
	SDL_Renderer		*renderer;
	TTF_Font			*font;
	TTF_Font			*font_m;
	Mix_Music			*music[2];
	Mix_Chunk			*effect[3];
	TTF_Font			*font_e;
	SDL_Color			color;
	SDL_Texture			*state[4];
	SDL_Rect			pos_state[7];
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
void				menu_loop(t_sdl *sdl, SDL_Surface *sur, SDL_Texture **tex);
void				end(t_sdl *sdl, int win);
void				render_plates(t_sdl *sdl, int i, double angle);
int					end_loop(SDL_Event event);
void				sound(t_sdl *sdl, int *son);
void				init_sound(t_sdl *sdl);
char				rcolor(int life);
char				gcolor(int life);
void				color_picker(SDL_Color *col, int hexa, int alpha);
void				render_healthbar(t_sdl *sdl, SDL_Rect pos, int i);
void				render_stats(t_sdl *sdl);
void				render_state(t_sdl *sdl, SDL_Rect pos, int i);
void				render_text(char *s, SDL_Color *color, SDL_Rect *pos,
	t_sdl *sdl);
void				init_state_pos(t_sdl *sdl);
void				render_states(t_sdl *sdl);
void				display_state(int state, t_sdl *sdl);

#endif