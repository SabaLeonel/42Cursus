/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:16:13 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/23 19:13:57 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutexlist(t_state *data, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i ++;
	}
	free(data->fork);
	return (-1);
}

int	init_mutex(t_state *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (destroy_mutexlist(data, i));
		i ++;
	}
	if (pthread_mutex_init(&data->mutex_print, NULL))
		return (destroy_mutexlist(data, i));
	return (0);
}

void	init_philo(t_state *data)
{
	int	i;

	i = -1;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		error("Malloc failed philo");
	printf("%p\n", data->philo);
	while (++i < data->nb_philo)
	{
		// data->philo[i] = (t_philo *)malloc(sizeof(t_philo));
		// if (!data->philo[i])
		// 	error("Failed Malloc")
		data->philo[i].time_lastmeal = get_time();
		printf("%llu", data->philo[i].time_lastmeal);
		data->philo[i].id = i + 1;
		data->philo[i].fork_left_id = i;
		if (i == 0)
			data->philo[i].fork_right_id = data->nb_philo - 1;
		else
			data->philo[i].fork_right_id = i + 1;
		data->philo[i].data = data;
		if (pthread_create(&data->philo[i].thread,
				NULL, &routine, &(data->philo[i])))
			error("Failed to create thread");
	}
	// check_state(data);
}

void	init_table(t_state *data, char **av)
{
	if (check_args(av, data))
		error("Arguments are not valid");
	data->start_time = get_time();
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nb_philo);
	if (!data->fork)
		error("Malloc fork failed");
	if (init_mutex(data))
		error("Init mutex failed");
	init_philo(data);
}
