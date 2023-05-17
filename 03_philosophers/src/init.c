/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:16:13 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/17 18:52:54 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutexlist(t_state *data, int len)
{
	int i;
	while (i < len)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i ++;
	}
	free(data->fork);
	return (-1);
}

int		init_mutex(t_state *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_init(data->fork[i]))
			return (destroy_mutexlist(data, i));
		i ++;
	}
	if (pthread_mutex_init(&data->mutex_print, NULL))
		return (destroy_mutexlist(data, i));
	
}

unsigned long long get_time()
{
	struct timeval time;

	getimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	init_philo(t_state *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].time_lastmeal = get_time();
		data->philo[i].id = i + 1;
		data->philo[i].fork_left_id = i;
		if (i == 0)
			data->philo[i].fork_right_id = data->nb_philo - 1;
		else
			data->philo[i].fork_right_id = i + 1;
		if (pthread_create(&data->philo[i].thread, NULL, &routine, &(data->philo[i])))
			error("Failed to create thread");
	}
	check_state(data);
}

void	init_table(t_state *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_eat = ft_atoi(av[5]);
	if (data->tt_die < 1 || data->tt_eat < 1
		|| data->tt_sleep < 1 || data->nb_philo < 2)
		error("Wrong arguments");
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nb_philo);
	if (!data->fork)
		error("Malloc fork failed");
	if (init_mutex(data))
		error("Init mutex failed");
	init_philo(data);
}
