#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define thread_num 7
#define max_meals 10

int		chopstick[thread_num] = {1, 1, 1, 1, 1, 1, 1};

pthread_mutex_t m[thread_num];

void	*philosopher(void *);

int		numMeals[thread_num] = {0, 0, 0, 0, 0, 0, 0};

int		p[thread_num] = {0, 1, 2, 3, 4, 5, 6};

int		g_mealCount = 0; // flemme de faire le temps

int		main(void)
{
	pthread_t	tid[thread_num];
	void		*status;
	int			i;

	i = 0;
	while (i < thread_num)
	{
		if (pthread_create(tid + i, NULL, philosopher, p + i) != 0)
		{
			perror("pthread_create fail");
			exit (0);
		}
		i++;
	}
	i = 0;
	while (i < thread_num)
	{
		if (!pthread_join(tid[i], &status) == 0)
		{
			perror("thr_join fail");
			exit (0);
		}
	}
}

void	*philosopher(void *arg)
{
	int		sub;

	sub = *(int *)arg;
	while (g_mealCount < max_meals)
	{
		printf ("\n%d repas mange sur %d\n\n", g_mealCount, max_meals);
		printf("philo : %d va manger\n", sub);
		pthread_mutex_lock(m + sub); //baguette gauche lock
		if (chopstick[sub] == 1)
		{
			chopstick[sub] = 0; //lock de la baguette
			//gauche dispo
			printf ("philo %d jai la gauche\n", sub);
			printf ("debug %d :left = %d\n\n", sub, chopstick[sub]);
//			pthread_mutex_unlock(m + sub);
//			pthread_mutex_lock(m + ((sub + 1) % thread_num));
			pthread_mutex_lock(m + sub + 1);
			if (chopstick[(sub + 1) % thread_num] == 1)
			{
				chopstick[(sub + 1) % thread_num] = 0;
				//baguette de droite dispo
				printf ("debug %d : right = %d\n", sub,
					chopstick[sub + 1] % thread_num);
//				pthread_mutex_unlock (m + ((sub + 1) % thread_num));
				printf ("debug j ai deux baguettes\n\n");
				numMeals[sub]++;
				g_mealCount++;
				usleep(100000000); //temps pour manger
//				pthread_mutex_lock (m + sub);
//				pthread_mutex_lock (m + (sub + 1) % thread_num);
//				chopstick[sub] = 1; // baguette gauche dispo
//				chopstick[(sub + 1)%thread_num] = 1;
				pthread_mutex_unlock (m + sub);
//				pthread_mutex_unlock (&m[(sub + 1)%thread_num]);
				usleep(100000000); //attente avant de pouvoir remanger
			}
			else
			{
				printf ("droite pas dispo\n\n");
				pthread_mutex_unlock (&m[(sub + 1) % thread_num]);
				pthread_mutex_lock (&m[sub]);
				chopstick[sub] = 1;
				pthread_mutex_unlock (&m[sub]);
				usleep (10000); // attente jusqu a un prochain essaye
			}
		}
		else
		{
			printf ("pas de baguette gauche\n\n");
			pthread_mutex_lock(&m[sub]);
			usleep(10000);
		}
	}
	exit (0);
}