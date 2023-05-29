/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/29 13:55:05 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

void	free_all(t_state data)
{
	int	i;

	i = -1;
	while (++i < data.nb_philo)
	{
		if (data.philo[i].checkfork)
			pthread_mutex_destroy(&data.philo[i].fork);
		if (data.philo[i].thread)
			pthread_detach(data.philo[i].thread);
	}
	if (data.philo)
		free (data.philo);
	if (data.m_dead)
		pthread_mutex_destroy(data.m_dead);
	if (data.m_nb_eat)
		pthread_mutex_destroy(data.m_nb_eat);
	if (data.m_print)
		pthread_mutex_destroy(data.m_print);
}

int	main(int argc, char **av)
{
	t_table	table;

	table = (t_table){};
	table.data = (t_state){};
	if (argc < 5 || argc > 6)
		return (error("Invalid number of arguments"));
	if (init_table(&table, av) || init_philo(&table))
	{
		free_all(table.data);
		return (error("Bad arguments"));
	}
	free_all(table.data);
	return (0);
}
