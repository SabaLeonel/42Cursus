/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/25 19:57:45 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <pthread.h>
# include <sys/time.h>

enum e_philo
{
	EAT,
	FORK,
	SLEEP,
	THINK,
	DEAD,
};

typedef struct s_philo	t_philo;

typedef struct s_state
{
	unsigned long long	tt_die;
	unsigned long long	tt_eat;
	unsigned long long	tt_sleep;
	int					nb_philo;
	int					nb_eat;
	int					dead;
	unsigned long long	start_time;
	t_philo				*philo;
	pthread_mutex_t		*mutex_print;
	pthread_mutex_t		*mutex_full_philo;
	int					*full_philo;
}	t_state;

typedef struct s_table
{
	t_state				data;
	int					full_philo;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_full_philo;
}	t_table;


typedef struct s_philo
{
	t_state				data;
	int					id;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		fork;
	unsigned long long	time_lastmeal;
	pthread_t			thread;
	int					nb_ate;
	int					dead;
}	t_philo;

int					ft_atoi(const char *str);
int					error(char *msg);
void				*routine(void *philo);
void				isdead(t_philo *philo);
void 				isfull(t_philo *philo);
int					check_args(char **av, t_table *table);
void				init_table(t_table *table, char **av);
void				init_philo(t_table *table);
unsigned long long	get_time(void);
int					ft_isdigit(int c);
void				eat(t_philo *philo);
void				print_action(t_philo *philo, enum e_philo action);
void				ft_usleep(unsigned long long tt_eat);
#endif