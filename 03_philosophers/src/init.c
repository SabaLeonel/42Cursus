/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:16:13 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/25 20:08:41 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	destroy_mutexlist(t_table *table, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		pthread_mutex_destroy(&table->data.fork[i]);
// 		i ++;
// 	}
// 	free(table->data.fork);
// 	return (-1);
// }

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->data.philo->fork, 0))
		return (-1);
	if (pthread_mutex_init(&table->data.philo->fork_r, 0))
		return (-1);
	if (pthread_mutex_init(&table->data.mutex_print, 0))
		return (-1);
	table->data.mutex_print = &table->mutex_print;
	if (pthread_mutex_init(&table->full_philo, 0))
		return (-1);
	table->data.mutex_full_philo = &table->mutex_full_philo;
	return (0);
}

void	init_philo(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->data.nb_philo)
	{
		table->data.philo[i].data = table->data;
		table->data.philo[i].id = i + 1;
		if (table->data.philo[i].id < table->data.nb_philo)
			table->data.philo[i].fork_r = &table->data.philo[i + 1].fork;
		else
			table->data.philo[i].fork_r = &table->data.philo[0].fork;
		if (pthread_create(&table->data.philo[i].thread,
				NULL, &routine, &(table->data.philo[i])))
		// table->data.philo[i].time_lastmeal = get_time();
			error("Failed to create thread");
	}
	i = -1;
	while(i < table->data.nb_philo)
	{
		if (pthread_join(&table->data.philo[i], 0));
			error("Can't join thread");
	}
}

void	init_table(t_table *table, char **av)
{
	if (check_args(av, table))
		error("Arguments are not valid");
	table->data.start_time = get_time();
	//table->data.fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->data.nb_philo);
	// if (!data->fork)
	// 	error("Malloc fork failed");
	if (init_mutex(table))
		error("Init mutex failed");
	table->data.full_philo = &table->full_philo;
	// table->data.dead = &table->dead;
	table->data.philo = (t_philo *)malloc(sizeof(t_philo) * table->data.nb_philo);
	if (!table->data.philo)
		error("Malloc failed philo");
	init_philo(table);
}
