/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/06/13 16:42:50 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

void	join_threads(t_state *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(data->philo[i].thread, NULL);
}

void	free_all(t_state data)
{
	int	i;

	i = -1;
	if (pthread_join(data.thread_check, NULL))
		perror("Error: can't join thread");
	while (i++ < data.nb_philo)
	{
		pthread_join(data.philo[i].thread, NULL);
		if (data.philo[i].checkfork)
			pthread_mutex_destroy(&data.philo[i].fork);
		if (data.philo[i].dead)
			pthread_mutex_destroy(&data.philo[i].m_dead);
	}
	pthread_join(data.thread_check, NULL);
	if (data.philo)
		free(data.philo);
	if (data.m_dead)
		pthread_mutex_destroy(data.m_dead);
	if (data.m_eat)
		pthread_mutex_destroy(data.m_eat);
	if (data.m_print)
		pthread_mutex_destroy(data.m_print);
}

int	access_value_i(int *ptr, int *new_value)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
	int						current_value;

	pthread_mutex_lock(&mutex);
	if (new_value != NULL)
		*ptr = *new_value;
	current_value = *ptr;
	pthread_mutex_unlock(&mutex);
	return (current_value);
}

unsigned long long	access_value_l(unsigned long long *ptr,
	unsigned long long *new_value)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
	unsigned long long		current_value;

	pthread_mutex_lock(&mutex);
	if (new_value != NULL)
		*ptr = *new_value;
	current_value = *ptr;
	pthread_mutex_unlock(&mutex);
	return (current_value);
}

int	main(int argc, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (argc < 5 || argc > 6)
		return (error("Invalid number of arguments"));
	if (init_table(&table, av) || init_philo(&table)
		|| check_dead(&table.data))
	{
		free_all(table.data);
		return (error("Bad arguments"));
	}
	free_all(table.data);
	return (0);
}
