/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/16 14:17:49 by lsaba-qu         ###   ########.fr       */
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

enum
{
	EAT, 	// 0
	SLEEP, 	// 1
	THINK, 	// 2
	DEAD,	// 3
};

typedef struct s_philo t_philo;


typedef struct s_state
{
	unsigned long long	tt_die;
	unsigned long long	tt_eat;
	unsigned long long	tt_sleep;
	int					nb_philo;
	int					nb_eat;
	unsigned long long	start_time;
	int					min_meal;
	t_philo				*philo;
	pthread_mutex_t		*fork; // malloc nb of philo 5 philo 5 fourchette
	pthread_mutex_t		mutex_print;
} t_state;

typedef struct s_philo
{
	int					id;
	int					fork_left_id;
	int					fork_right_id;
	unsigned long long	time_lastmeal;
	pthread_t			thread;
	int					nb_ate;
} t_philo;


int	ft_atoi(const char *str);
int	error(char *msg);
#endif