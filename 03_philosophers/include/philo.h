/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/24 13:12:00 by lsaba-qu         ###   ########.fr       */
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
	int					all_dead;
	unsigned long long	start_time;
	int					max_meal;
	t_philo				*philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		mutex_print;
}	t_state;

typedef struct s_philo
{
	t_state				*data;
	int					id;
	int					fork_left_id;
	int					fork_right_id;
	unsigned long long	time_lastmeal;
	pthread_t			thread;
	int					nb_ate;
	int					dead;
}	t_philo;

int					ft_atoi(const char *str);
int					error(char *msg);
void				*routine(void *philo);
int					check_state(t_state *data);
int					check_all_eat(t_state *data);
int					check_args(char **av, t_state *data);
void				init_table(t_state *data, char **av);
void				init_threads(t_state *data);
void				init_philo(t_state *data);
unsigned long long	get_time(void);
int					ft_isdigit(int c);
void				eat(t_philo *philo);
void				print_action(t_philo *philo, enum e_philo action);
void				ft_wait(unsigned long long tt_eat, int dead);
#endif