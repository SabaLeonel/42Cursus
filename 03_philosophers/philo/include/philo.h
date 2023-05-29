/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/29 14:57:14 by lsaba-qu         ###   ########.fr       */
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
	unsigned long long	start_time;
	int					*full_philo;
	int					*dead;
	t_philo				*philo;
	pthread_mutex_t		*m_print;
	pthread_mutex_t		*m_nb_eat;
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
}	t_philo;

int					ft_atoi(const char *str);
int					error(char *msg);
void				*routine(void *philo);
int					isdead(t_philo *philo);
int					is_full(t_philo *philo);
int					check_args(char **av, t_table *table);
int					init_table(t_table *table, char **av);
int					init_philo(t_table *table);
unsigned long long	get_time(void);
int					ft_isdigit(int c);
void				eat(t_philo *philo);
void				print_action(t_philo *philo, enum e_philo action);
void				ft_usleep(unsigned long long tt_eat);
#endif