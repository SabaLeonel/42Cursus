/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/11 17:07:21 by lsaba-qu         ###   ########.fr       */
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


typedef struct s_time
{
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	unsigned long long	start_time;
	int					min_meal;

	pthread_mutex_t		*print_mutex;
	pthread_mutex_t		*full_mutex;
	int					*full_philo;
	
} t_time;


typedef	struct s_share
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t full_mutex;
	int				full_philo;
	t_philo			*philo;
	t_time			time;
}	t_share;

typedef struct s_philo
{
	int					id;
	pthread_mutex_t		fork;
	pthread_mutex_t		*next_fork;
	pthread_t			thread;
	int					status;
	int					cptmeal;
	t_time				time;
	t_share				*share;
	unsigned long long	time_lastmeal;
} t_philo;


int	ft_atoi(const char *str);
int	error(char *msg);
#endif