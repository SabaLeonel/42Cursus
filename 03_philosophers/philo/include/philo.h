/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/06/13 16:09:29 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <string.h>
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
	FULL,
};

typedef struct s_philo	t_philo;

typedef struct s_state
{
	unsigned long long	tt_die;
	unsigned long long	tt_eat;
	unsigned long long	tt_sleep;
	int					nb_philo;
	int					nb_eat;
	unsigned long long	start_time;
	int					*full_philo;
	int					*dead;
	int					value;
	pthread_t			thread_check;
	t_philo				*philo;
	pthread_mutex_t		*m_print;
	pthread_mutex_t		*m_eat;
	pthread_mutex_t		*m_dead;
}	t_state;

typedef struct s_table
{
	t_state				data;
	int					full_philo;
	int					dead;
	pthread_mutex_t		m_print;
	pthread_mutex_t		m_nb_eat;
	pthread_mutex_t		m_dead;
}	t_table;

typedef struct s_philo
{
	int					id;
	int					nb_ate;
	int					dead;
	int					checkfork;
	unsigned long long	time_lastmeal;
	t_state				data;
	pthread_t			thread;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		fork;
	pthread_mutex_t		m_dead;
}	t_philo;

int					ft_atoi(const char *str);
int					error(char *msg);
void				*routine(void *philo);
int					check_philo(t_state *data);
int					is_full(t_state *data);
int					check_args(char **av, t_table *table);
int					check_dead(t_state *data);
int					init_table(t_table *table, char **av);
int					init_philo(t_table *table);
unsigned long long	get_time(void);
int					ft_isdigit(int c);
void				eat(t_philo *philo);
void				print_action(t_philo *philo, enum e_philo action);
void				ft_usleep(unsigned long long time, t_philo *philo);
void				join_threads(t_state *data);
void				*routine_checker(void *data);
int					solo_philo(t_table *table);
char				*get_msg(enum e_philo action, char *msg);
int					access_value_i(int *ptr, int *new_value);
unsigned long long	access_value_l(unsigned long long *ptr,
						unsigned long long *new_value);
#endif